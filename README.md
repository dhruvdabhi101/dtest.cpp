# dtest.cpp

It is minimalistic testing framework written in C++, to meet your fast paced testing needs.

# How to run ?
- Download dtest.cpp and put it in your code directory
- import it via `#include "dtest.h"`
- use defined macros

# Example

```cpp

#include <iostream>
#include "dtest.h"

// Functions to test
int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

TEST(AllTest) 
    TEST_AND_PRINT(add(2, 3), 5);
    TEST_AND_PRINT(subtract(5, 3), 2);
    TEST_AND_PRINT(add(2, 2), 4);
END_TEST

TEST(SomeTest) 
    TEST_AND_PRINT(add(2, 3), 5);
    TEST_AND_PRINT(add(2, 2), 4);
END_TEST

RUN_ALL_TESTS
```


# TODOs
- [ ] Add more assert macros
    - [ ] ASSERT_EQ, ASSERT_NE, ASSERT_GT, ASSERT_LT etc.
- [ ] Add more clear errors
