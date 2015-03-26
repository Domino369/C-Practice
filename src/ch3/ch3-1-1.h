#ifndef CH3_1_1
#define CH3_1_1

#include <vector>
#include <list>

/**
 * Important Minor Syntax Cleanups
 */

class ISO11 {
  std::vector<std::list<int>> v;

public:
  void f(int);
  void f(void*);	// null pointer
};

class ISO03 {
  std::vector<std::list<int> > v;
  
public:
  void f(int);
  void f(void*);	// null pointer
};

void ch3_1_1();

#endif