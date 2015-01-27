#ifndef CHECK_H_
#define CHECK_H_

#include <cassert>
#define CHECK(x) if (!(x)) { assert(x); abort(); }

#endif // CHECK_H_
