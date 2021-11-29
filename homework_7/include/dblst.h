#pragma once
#include <iostream>
template <typename T>
class DBlist {
  struct Node {
    T value;     // data 
    Node *next;  // ссылка следующий элемент
    Node *prev;  // ссылка пердыдущий элемент
  };
  Node *head;  // начало списка
  Node *tail;  // конец списка
  int count;

 public:
  DBlist();
  DBlist(const DBlist<T> &list);
  DBlist &operator=(const DBlist<T> &list);

  int size() const; 
  bool is_empty() const; 
  T &operator[](int index);
  void push_first(const T &value);
  void push_back(const T &value);
  void push_medium(const T &value);
  void insert(int index,const T &value);
  void remove_front(); 
  void remove_back();  
  void remove_medium(); 
  void erase(int index);
  void all_map() const; 
  ~DBlist();
};

template <typename T>
DBlist<T>::DBlist() {
  head = nullptr;
  tail = nullptr;
  count = 0;
}
template <typename T>
DBlist<T>::DBlist(const DBlist<T> &list) {
  head = nullptr;
  tail = nullptr;
  count = list.count;
  if (list.head == nullptr) return;
  for (Node *orig = list.head; orig != nullptr; orig = orig->next) {
    Node *node = new Node;
    node->value = orig->value;
    node->next = nullptr;
    node->prev = tail;
    if (tail == nullptr) {
      head = node;
    } else {
      tail->next = node;
    }
    tail = node;
  }
}
template <typename T>
DBlist<T> &DBlist<T>::operator=(const DBlist<T> &list) {
  if (this == &list) return *this;

  while (head) {
    Node *tmp = head;
    head = head->next;
    delete tmp;
  }

  tail = nullptr;

  count = list.count;
  if (list.head == nullptr) return *this;
  for (Node *orig = list.head; orig != nullptr; orig = orig->next) {
    Node *node = new Node;
    node->value = orig->value;
    node->next = nullptr;
    node->prev = tail;
    if (tail == nullptr) {
      head = node;
    } else {
      tail->next = node;
    }
    tail = node;
  }
  return *this;
}
template <typename T>
int DBlist<T>::size() const {
  return count;
}
template <typename T>
bool DBlist<T>::is_empty() const {
	return count == 0;
}
template <typename T>
inline T &DBlist<T>::operator[](int index) {
  if (index < 0 || index >= count)
    throw std::out_of_range("DBlist::operator[index]: index out of bounds");
  Node *node = head;
  while (node != nullptr && index) {
    index--;
    node = node->next;
  }
  return node->value;
}
template <typename T>
void DBlist<T>::push_first(const T &value) {
  Node *node = new Node;
  node->value = value;
  node->prev = nullptr;
  node->next = head;
  if (head == nullptr) {
    tail = node;
  } else {
    head->prev = node;
  }
  head = node;
  count++;
}
template <typename T>
void DBlist<T>::push_back(const T &value) {
  Node *node = new Node;

  node->value = value;
  node->prev = tail;
  node->next = nullptr;
  if (tail == nullptr) {
    head = node;
  } else {
    tail->next = node;
  }
  tail = node;
  count++;
}
template <typename T>
void DBlist<T>::push_medium(const T &value){
  insert(count/2,value);
}
template <typename T>
void DBlist<T>::insert(int index,const T &value) {
  if (index < 0 || index >= count)
		throw std::out_of_range("DBlist::insert(index): index out of bounds");
  Node *prev = head;
  while (index - 1) {
    index--;
    prev = prev->next;
  }
  Node *node = new Node;
  if (prev->next == tail) tail->prev = node;
  node->value = value;
  node->next = prev->next;
  prev->next->prev = node;
  prev->next = node;
  node->prev = prev;
  count++;
}
template <typename T>
void DBlist<T>::remove_front() {
	// если список пуст исключение
	if (is_empty())
		throw std::out_of_range("DBlist::remove_front: list is empty"); 
	Node *tmp = head; 
  head = head->next; 
	delete tmp;
	count--; 
	if (head == nullptr) {
    tail = nullptr;
	}
	else {
		head->prev = nullptr;
	}
}
template <typename T>
void DBlist<T>::remove_back() {
	if (is_empty())
		throw std::out_of_range("DBlist::remove_back: list is empty"); // бросаем исключение
	Node *tmp = tail;
	tail = tail->prev; 
	delete tmp; 
	count--; 
	if (tail == nullptr) {
		head = nullptr; 
	}
	else {
		tail->next = nullptr; 
	}
}
template <typename T>
void DBlist<T>::remove_medium(){
erase(count/2-1);
}
template <typename T>
void DBlist<T>::erase(int index) {
  if (index < 0 || index >= count) {
    throw std::out_of_range("DBlist::erase(index): index out of bounds");
  }
  Node *prev = nullptr;
  Node *node = head;
  while (index) {
    index--;
    prev = node;
    node = node->next;
  }
  count--;            
  Node *tmp = node;  
  prev->next = node->next;   
  node->next->prev = prev;   
  delete tmp;
}
template <typename T>
void DBlist<T>::all_map() const {
  Node *node = head;

  while (node != nullptr) {
    if (node == head) {
      std::cout << node->value;
    } else {
      std::cout << ", " << node->value;
    }
    node = node->next;
  }
  std::cout << "\n";
}
template <typename T>
DBlist<T>::~DBlist() {
  while (head) {
    Node *tmp = head;
    head = head->next;
    delete tmp;
  }
  tail = nullptr;
}
