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
  
  int size() const;
  bool is_empty()const;
  T &operator[](int index);
  void push_first(T data);
  void push_back(T data);
  void push_medium(T data);
  void insert(int index, T data);
  void remove_front();
  void remove_back();
  void remove_medium();
  void erase(int index);
  void all_map();
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
  region = nullptr;
}

template <typename T>
vctr<T>::vctr(int n, T data) {
  count = capacity = n;
  region = (n == 0) ? nullptr : new T[n];
  for (int i = 0; i < n; i++) {
    region[i] = data;
  }
}
template <typename T>
vctr<T>::vctr(const vctr &src) {
  vctr_copy(src);
}
template <typename T>
vctr<T> &vctr<T>::operator=(const vctr &src) {
  if (this != &src) {
    if (region != nullptr) delete[] region;
    vctr_copy(src);
  }
  return *this;
}
template <typename T>
int vctr<T>::size() const {
  return count;
}
template <typename T>
bool vctr<T>::is_empty() const {
   return count == 0;
}
template <typename T>
T &vctr<T>::operator[](int index) {
  if (index < 0 || index >= count)
    throw std::out_of_range("vctr::operator[index]: index out of bounds");
  return region[index];
}
template <typename T>
void vctr<T>::push_first(T data) {
  insert(0, data);
}
template <typename T>
void vctr<T>::push_back(T data) {
  insert(count, data);
}
template <typename T>
void vctr<T>::push_medium(T data) {
  insert(count / 2, data);
}
template <typename T>
void vctr<T>::insert(int index, T data) {
  if (count == capacity) up_capacity();
  if (index < 0 || index > count) {
    throw std::out_of_range("vctr::insert(index) out of range");
  }
  for (int i = count; i > index; i--) {
    region[i] = region[i - 1];
  }
  region[index] = data;
  count++;
}
template <typename T>
void vctr<T>::remove_front(){
  erase(0);
}
template <typename T>
void vctr<T>::remove_back(){
  erase(count-1);
}
template <typename T>
void vctr<T>::remove_medium(){
  erase(count/2-1);
}
template <typename T>
void vctr<T>::erase(int index) {
  if (index < 0 || index >= count) {
    throw std::out_of_range("vctr::erase(index) out of range");
  }
  for (int i = index; i < count - 1; i++) {
    region[i] = region[i + 1];
  }
  count--;
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
vctr<T>::~vctr() {
  if (region != nullptr) {delete[] region;
  std::cout<<"Run Destructor";
  }
  
}
template <typename T>
void vctr<T>::up_capacity() {
  capacity = std::max(1, capacity * 2);
  T *array = new T[capacity];
  for (int i = 0; i < count; i++) {
    array[i] = region[i];
  }
  if (region != nullptr) delete[] region;
  region = array;
}
template <typename T>
void vctr<T>::vctr_copy(const vctr &src) {
  count = capacity = src.count;
  region = (capacity == 0) ? nullptr : new T[capacity];
  for (int i = 0; i < count; i++) {
    region[i] = src.region[i];
  }
}
