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

#endif
