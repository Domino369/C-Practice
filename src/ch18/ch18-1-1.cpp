#include "ch18-1-1.h"

#include <thread>
#include <chrono>
#include <random>
#include <iostream>
#include <exception>
#include <list>

using namespace std;

int do_something(char c) {
	// random number generator using c as seed to get different sequences
	default_random_engine dre(c);
	uniform_int_distribution<int> id(10, 1000);
	
	// loop to pring characer after a random period of time
	for (int i = 0; i < 10; ++i) {
		this_thread::sleep_for(chrono::milliseconds(id(dre)));
		cout.put(c).flush();
	}
	
	return c;
}

int func1() {
	return do_something('.');
}


int func2() {
	return do_something('+');
}

void task1() {
	// endless insertion and memory allocation
	// - will sooner or later raise an exception
	// - BEWARE: this is bad practice
	list<int> v;
	while (true) {
		for (int i = 0; i < 1000000; ++i) {
			v.push_back(i);
		}
		cout.put('.').flush();
	}
}

int quick_computation() { // process result "quick and dirty"
	return 0;
}

int accurate_computation() { // process result "accurate but slow"
	return 0 * 0 * 0 * 0;
}

std::future<int> f; // outside declared because lifetime of accruate_computation()
					// might exceed lifetime of best_result_in_time()

int best_result_in_time() {
	// define time slot to get the answer:
	auto tp = chrono::system_clock::now() + chrono::minutes(1);
	
	// start both a quick and an accurate computation:
	f = async(launch::async, accurate_computation);
	int guess = quick_computation();
	
	// give accurate computation the rest of the time slot:
	future_status s = f.wait_until(tp);
	
	// return the best computation result we have:
	if (s == future_status::ready) {
		return f.get();
	} else {
		return guess;	// accurate_computation() continues
	}
}

void basic_async() {
	cout << "~Basic launch policy~" << endl << endl;
	
	cout << "starting funct1() in background"
		 << " and func2() in foreground:" << endl;
		 
	// start func1() asynchronously *now or later or never):
	future<int> result1(async(launch::async, func1));
	
	int result2 = func2();	// call func2() synchronously (here and now)
	
	// print result (wait for func1() to finish and add its result to result2)
	int result = result1.get() + result2;
	
	cout << endl << "result of func1()+func2(): " << result
		 << endl << endl;
}

void double_async() {
	cout << "~Using auto with differed policies and both async~" << endl << endl;
		 
	cout << "starting funct1() in background"
		 << " and func2() in foreground:" << endl;
	
	auto f1 = async(launch::async, func1);
	auto f2 = async(launch::async, func2);
	
	// deferred; fuunc never gets called without get or wait
//	auto f1 = async(launch::deferred, func1);
//	auto f2 = async(launch::deferred, func2);
	
	int result = f1.get() + f2.get();
	
	cout << endl << "result of func1()+func2(): " << result
		 << endl << endl;
}

void async_exceptions() {
	cout << "starting 2 tasks" << endl;
	cout << "- task1: process endless loop of memory consumption" << endl;
	cout << "- task2: wait for <return> and then for task1" << endl;
	
	auto f3 = async(task1);	// start task1() asynchronously (now or later or never)
	
	cin.get();	// read a character (like getchar())
	
	cout << endl << "wait for the end of task1: " << endl;
	try {
		f3.get();	// wait for task1() to finish (raises exception if any)
	} catch (const exception& e) {
		cerr << "EXCEPTION: " << e.what() << endl;
	}
	
	cout << endl << endl;
}

void waits() {
	// wait
	future<int> f4(async(func1));	// try to call func1 asynchronously
	f4.wait();
	
	// wait_for
	future<int> f5(async(func1));	// try to call func1 asynchronously
	f5.wait_for(chrono::seconds(10));
	
	// wait_until
	future<int> f6(async(func1));	// try to call func1 asynchronously
	f6.wait_until(chrono::system_clock::now() + std::chrono::minutes(1));
}

void ch18_1_1() {
	basic_async();
	double_async();
	async_exceptions();
	waits();
	
	best_result_in_time();
	
	// polling
	future<int> ff(async(func1));	// try to call task asynchronously
	if (ff.wait_for(chrono::seconds(0)) != future_status::deferred) {
		while (ff.wait_for(chrono::seconds(0)) != future_status::ready) {
			this_thread::yield();
		}
	}
	auto r = ff.get();	// force execution of task and wait for result (or exception)
	cout << r << endl;
}
