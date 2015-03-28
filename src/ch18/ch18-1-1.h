#ifndef CH18_1_1
#define CH18_1_1

/**
 * First Example Using async() and Futures
 */

#include <future>

int do_something(char c);
int func1();
int func2();
void task1();
int quick_computation();
int accurate_computation();
int best_result_in_time();

void basic_async();
void double_async();
void async_exceptions();
void waits();

void ch18_1_1();

#endif
