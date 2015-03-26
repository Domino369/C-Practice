#include <cstdio>
#include <cstddef>

#include "ch3-1-1.h"

using namespace std;

void ISO11::f(int) {
  printf("f() = number\r\n");
}

void ISO11::f(void*) {
  printf("f() = null\r\n");
}

void ch3_1_1() {
  ISO11 iso11;
  ISO03 iso03;
  
  iso11.f(0);
//  iso11.f(NULL); // Doesn't like this
  iso11.f(nullptr);
}