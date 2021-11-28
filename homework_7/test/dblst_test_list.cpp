
#include "./dblst.h"
#include <gtest/gtest.h>

TEST(dblst, push_back) {
  // Arrange
  const size_t count = 10;
  DBlist<size_t> _dblst;

  // Act
  for (size_t i = 0; i < count; ++i) {
    _dblst.push_back(i);
  }
  // Assert
  ASSERT_EQ(_dblst.size(), count);
}
