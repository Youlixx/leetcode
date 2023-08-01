#ifndef __UTILS_HPP__
#define __UTILS_HPP__

#include <gtest/gtest.h>

#ifndef ASSERT_VECTOR_EQUAL
#define ASSERT_VECTOR_EQUAL(x, y)                                              \
  {                                                                            \
    ASSERT_EQ(x.size(), y.size());                                             \
    for (int index{0}; index < x.size(); index++) {                            \
      EXPECT_EQ(x[index], y[index]);                                           \
    }                                                                          \
  }
#endif

#ifndef ASSERT_VECTOR_NESTED_EQUAL
#define ASSERT_VECTOR_NESTED_EQUAL(x, y)                                       \
  {                                                                            \
    ASSERT_EQ(x.size(), y.size());                                             \
    for (int outerIndex{0}; outerIndex < x.size(); outerIndex++) {             \
      ASSERT_VECTOR_EQUAL(x[outerIndex], y[outerIndex]);                       \
    }                                                                          \
  }
#endif

#endif
