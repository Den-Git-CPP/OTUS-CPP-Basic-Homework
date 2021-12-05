#include "./vctr.h"
#include <gtest/gtest.h>

TEST(vctr, DefaultConstructor) {
  // Act
  vctr<int> _vector;
  // Assert
  ASSERT_EQ(_vector.size(), 0);
}

TEST(vctr, is_empty) {
  // Act
  vctr<int> _vector;
  // Assert
  ASSERT_TRUE(_vector.is_empty());
}

TEST(vctr, not_is_empty) {
  // Act
  vctr<int> _vector;
  _vector.push_back(5);
  // Assert
  ASSERT_FALSE(_vector.is_empty());
}

TEST(vctr, push_first) {
  // Arrange
  vctr<int> _vector;
  for (int i = 0; i < 10; ++i) {
    _vector.push_back(i);
  }
  // Act
  _vector.push_first(10);
  // Assert
  ASSERT_EQ(_vector[0], 10);
  ASSERT_EQ(_vector[1], 0);
}

TEST(vctr, push_back) {
  // Arrange
  vctr<int> _vector;
  for (int i = 0; i < 10; ++i) {
    _vector.push_back(i);
  }
  // Act
  _vector.push_back(30);
  // Assert
  ASSERT_EQ(_vector[9], 9);
  ASSERT_EQ(_vector[10], 30);
}

TEST(vctr, push_medium) {
  // Arrange
  vctr<int> _vector;
  for (int i = 0; i < 10; ++i) {
    _vector.push_back(i);
  }
  // Act
  _vector.push_medium(20);
  // Assert
  ASSERT_EQ(_vector[5], 20);
}

TEST(vctr, remove_front) {
  // Arrange
  vctr<int> _vector;
  for (int i = 0; i < 10; ++i) {
    _vector.push_back(i);
  }
  // Act
  _vector.remove_front();
  // Assert
  ASSERT_EQ(_vector[0], 1);
  ASSERT_EQ(_vector[1], 2);
}

TEST(vctr, remove_back) {
  // Arrange
  vctr<int> _vector;
  for (int i = 0; i < 10; ++i) {
    _vector.push_back(i);
  }
  // Act
  _vector.remove_back();
  // Assert
  ASSERT_EQ(_vector.size(), 9);
}

TEST(vctr, remove_medium) {
  // Arrange
  vctr<int> _vector;
  for (int i = 0; i < 10; ++i) {
    _vector.push_back(i);
  }
  // Act
  _vector.remove_medium();
  // Assert
  ASSERT_EQ(_vector[4], 5);
  ASSERT_EQ(_vector[_vector.size() - 1], 9);
}

TEST(vctr, at_index) {
  // Arrange
  vctr<int> _vector;
  for (int i = 0; i < 10; ++i) {
    _vector.push_back(i);
  }
  // Act
  // Assert
  ASSERT_EQ(_vector[0], 0);
  ASSERT_EQ(_vector[9], 9);
}

TEST(vctr, size) { 
  // Arrange
  vctr<int> _vector;
  for (int i = 0; i < 10; ++i) {
    _vector.push_back(i);
  }
  // Act
  // Assert
  ASSERT_EQ(_vector.size(), 10);
}

TEST(vctr, out_of_range_operator_indexing) { 
  // Arrange
  vctr<int> _vector;
  for (int i = 0; i < 10; ++i) {
    _vector.push_back(i);
  }
  try {
        _vector[20];
        FAIL() << "vctr::operator[index]: index out of bounds";
    }
    catch(std::out_of_range const & err) {
        EXPECT_EQ(err.what(),std::string("vctr::operator[index]: index out of bounds"));
    }
}

TEST(vctr, out_of_range_insert) { 
  // Arrange
  vctr<int> _vector;
  for (int i = 0; i < 10; ++i) {
    _vector.push_back(i);
  }
  try {//Act
      _vector.insert(20,20);
        FAIL() << "vctr::insert(index) out of range";
    }// Assert
    catch(std::out_of_range const & err) {
        EXPECT_EQ(err.what(),std::string("vctr::insert(index) out of range"));
    }
}

TEST(vctr, out_of_range_erase){
// Arrange
  vctr<int> _vector;
  for (int i = 0; i < 10; ++i) {
    _vector.push_back(i);
  }
try { //Act
        _vector.erase(30);
        FAIL() << "vctr::erase(index) out of range";
    }// Assert    
    catch(std::out_of_range const & err) {
        EXPECT_EQ(err.what(),std::string("vctr::erase(index) out of range"));
  }

}

TEST(vctr, v_copy) {
  // Arrange
  vctr<int> vector1;
  vctr<int> vector2;
  for (int i = 0; i < 10; ++i) {
    vector1.push_back(i);
  }
  // Act
  vector2=vector1;
  // Assert
  for (int i = 0; i < 10; ++i) {
  ASSERT_EQ(vector1[i], vector2[i]);
  }
}



