
#include "./dblst.h"
#include <gtest/gtest.h>

TEST(DBlist, DefaultConstructor) {
  // Act
  DBlist<int> _dblst;
  // Assert
  ASSERT_EQ(_dblst.size(), 0);
}

TEST(DBlist, is_empty) {
  // Act
  DBlist<int> _dblst;
  // Assert
  ASSERT_TRUE(_dblst.is_empty());
}

TEST(DBlist, not_is_empty) {
  // Act
  DBlist<int> _dblst;
  _dblst.push_back(5);
  // Assert
  ASSERT_FALSE(_dblst.is_empty());
}

TEST(DBlist, push_first) {
  // Arrange
  DBlist<int> _dblst;
  for (int i = 0; i < 10; ++i) {
    _dblst.push_back(i);
  }
  // Act
  _dblst.push_first(10);
  // Assert
  ASSERT_EQ(_dblst[0], 10);
  ASSERT_EQ(_dblst[1], 0);
}

TEST(DBlist, push_back) {
  // Arrange
  DBlist<int> _dblst;
  for (int i = 0; i < 10; ++i) {
    _dblst.push_back(i);
  }
  // Act
  _dblst.push_back(30);
  // Assert
  ASSERT_EQ(_dblst[9], 9);
  ASSERT_EQ(_dblst[10], 30);
}

TEST(DBlist, push_medium) {
  // Arrange
  DBlist<int> _dblst;
  for (int i = 0; i < 10; ++i) {
    _dblst.push_back(i);
  }
  // Act
  _dblst.push_medium(20);
  // Assert
  ASSERT_EQ(_dblst[5], 20);
}

TEST(DBlist, remove_front) {
  // Arrange
  DBlist<int> _dblst;
  for (int i = 0; i < 10; ++i) {
    _dblst.push_back(i);
  }
  // Act
  _dblst.remove_front();
  // Assert
  ASSERT_EQ(_dblst[0], 1);
  ASSERT_EQ(_dblst[1], 2);
}

TEST(DBlist, remove_back) {
  // Arrange
  DBlist<int> _dblst;
  for (int i = 0; i < 10; ++i) {
    _dblst.push_back(i);
  }
  // Act
  _dblst.remove_back();
  // Assert
  ASSERT_EQ(_dblst.size(), 9);
}

TEST(DBlist, remove_medium) {
  // Arrange
  DBlist<int> _dblst;
  for (int i = 0; i < 10; ++i) {
    _dblst.push_back(i);
  }
  // Act
  _dblst.remove_medium();
  // Assert
  ASSERT_EQ(_dblst[4], 5);
  ASSERT_EQ(_dblst[_dblst.size() - 1], 9);
}

TEST(DBlist, at_index) {
  // Arrange
  DBlist<int> _dblst;
  for (int i = 0; i < 10; ++i) {
    _dblst.push_back(i);
  }
  // Act
  // Assert
  ASSERT_EQ(_dblst[0], 0);
  ASSERT_EQ(_dblst[9], 9);
}

TEST(DBlist, size) { 
  // Arrange
  DBlist<int> _dblst;
  for (int i = 0; i < 10; ++i) {
    _dblst.push_back(i);
  }
  // Act
  // Assert
  ASSERT_EQ(_dblst.size(), 10);
}

TEST(DBlist, out_of_range_operator_indexing) { 
  // Arrange
  DBlist<int> _dblst;
  for (int i = 0; i < 10; ++i) {
    _dblst.push_back(i);
  }
  try {
        _dblst[20];
        FAIL() << "DBlist::operator[index]: index out of bounds";
    }
    catch(std::out_of_range const & err) {
        EXPECT_EQ(err.what(),std::string("DBlist::operator[index]: index out of bounds"));
    }
}

TEST(DBlist, out_of_range_insert) { 
  // Arrange
  DBlist<int> _dblst;
  for (int i = 0; i < 10; ++i) {
    _dblst.push_back(i);
  }
  try {//Act
      _dblst.insert(20,20);
        FAIL() << "DBlist::insert(index): index out of bounds";
    }// Assert
    catch(std::out_of_range const & err) {
        EXPECT_EQ(err.what(),std::string("DBlist::insert(index): index out of bounds"));
    }
}

TEST(DBlist, out_of_range_erase){
// Arrange
  DBlist<int> _dblst;
  for (int i = 0; i < 10; ++i) {
    _dblst.push_back(i);
  }
try { //Act
        _dblst.erase(30);
        FAIL() << "DBlist::erase(index): index out of bounds";
    }// Assert    
    catch(std::out_of_range const & err) {
        EXPECT_EQ(err.what(),std::string("DBlist::erase(index): index out of bounds"));
  }

}