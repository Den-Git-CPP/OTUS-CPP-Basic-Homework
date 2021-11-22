#pragma once
#include <algorithm>
#include <iostream>

template <typename T>
class vctr {
 public:
  vctr();
  explicit vctr(int n, T data = T());
  vctr(const vctr &src);
  vctr &operator=(const vctr &src);

  void insert(int index, T data);
  void remove(int index);
  void push_first(T data);
  void push_medium(T data);
  void push_back(T data);
  void all_map();
  int size() const;
  T &operator[](int index);
  ~vctr();

 private:
  T *region;
  int capacity;
  int count;
  void up_capacity();
  void vctr_copy(const vctr &src);
};

template <typename T>
vctr<T>::vctr() {
  count = capacity = 0;
  region = NULL;
}
template <typename T>
void vctr<T>::insert(int index, T data) {
  if (count == capacity) up_capacity();
  if (index < 0 || index > count) {
    throw "vctr::insert(index) out of range";
  }
  for (int i = count; i > index; i--) {
    region[i] = region[i - 1];
  }
  region[index] = data;
  count++;
}
template <typename T>
vctr<T>::vctr(int n, T data) {
  count = capacity = n;
  region = (n == 0) ? NULL : new T[n];
  for (int i = 0; i < n; i++) {
    region[i] = data;
  }
}
template <typename T>
vctr<T>::vctr(const vctr &src) {
  deepCopy(src);
}
template <typename T>
vctr<T> &vctr<T>::operator=(const vctr &src) {
  if (this != &src) {
    if (region != NULL) delete[] region;
    deepCopy(src);
  }
  return *this;
}
template <typename T>
void vctr<T>::remove(int index) {
  if (index < 0 || index >= count) {
    throw "vctr::remove(index) out of range";
  }
  for (int i = index; i < count - 1; i++) {
    region[i] = region[i + 1];
  }
  count--;
}
template <typename T>
void vctr<T>::push_first(T data) {
  insert(0, data);
}
template <typename T>
void vctr<T>::push_medium(T data) {
  insert(count / 2, data);
}
template <typename T>
void vctr<T>::push_back(T data) {
  insert(count, data);
}
template <typename T>
void vctr<T>::all_map() {
  for (int i = 0; i < count; i++) {
    if (i == 0) {
      std::cout << region[i];
    } else {
      std::cout << ", " << region[i];
    }
  }
  std::cout << std::endl;
}
template <typename T>
T &vctr<T>::operator[](int index) {
  if (index < 0 || index >= count)
    std::cout << "vctr::operator[index]: index out of bounds";
  return region[index];
}
template <typename T>
int vctr<T>::size() const {
  return count;
}
template <typename T>
vctr<T>::~vctr() {
  if (region != NULL) delete[] region;
}
template <typename T>
void vctr<T>::up_capacity() {
  capacity = std::max(1, capacity * 2);
  T *array = new T[capacity];
  for (int i = 0; i < count; i++) {
    array[i] = region[i];
  }
  if (region != NULL) delete[] region;
  region = array;
}
template <typename T>
void vctr<T>::vctr_copy(const vctr &src) {
  count = capacity = src.count;
  region = (capacity == 0) ? NULL : new T[capacity];
  for (int i = 0; i < count; i++) {
    region[i] = src.region[i];
  }
}
