# dtest.cpp

It is minimalistic testing framework written in C++, to meet your fast paced testing needs.

# How to run ?
- Download dtest.cpp and put it in your code directory
- import it via `#include "dtest.h"`
- use defined macros

# Example

```cpp
#include "dtest.h"

int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

TEST(AllTest)
    ASSERT(true);
    ASSERT_EQ(add(2, 3), 5);
    ASSERT_EQ(subtract(5, 3), 2);
    ASSERT_EQ(add(2, 2), 4);
END_TEST

TEST(AddTest)
    ASSERT_EQ(add(2, 3), 5);
    ASSERT_EQ(add(2, 2), 4);
    ASSERT_NE(add(2, 2), 5);
END_TEST

RUN_ALL_TESTS
```

## Supported Macros
- ASSERT
- ASSERT_EQ
- ASSERT_NE


# TODOs
- [x] Add more assert macros
    - [x] ASSERT_EQ, ASSERT_NE etc.
