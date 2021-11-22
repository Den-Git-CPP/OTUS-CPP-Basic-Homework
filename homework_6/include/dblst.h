#pragma once
template <typename T>
class DBlist {
  struct Node {
    T value;     // значение элемента списка
    Node *next;  // ссылка на следующий элемент
    Node *prev;  // ссылка на предыдущий элемент
  };
  Node *head;  // начало списка
  Node *tail;  // конец списка
  int count;

 public:
  DBlist();
  DBlist(const DBlist<T> &list);
  DBlist &operator=(const DBlist<T> &list);
  int size() const;
  T &operator[](int index);
  void push_first(const T &value);
  void push_back(const T &value);
  void push_medium(const T &value);
  void remove_at(int index);
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
inline T &DBlist<T>::operator[](int index) {
  if (index < 0 || index >= count)
    throw "DBlist::operator[index]: index out of bounds";
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
void DBlist<T>::push_medium(const T &value) {
  int index = count / 2;

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
void DBlist<T>::remove_at(int index) {
  if (index < 0 || index >= count) {
    throw "DBlist::remove_at(index): index out of bounds";
  }
  Node *prev = nullptr;
  Node *node = head;
  while (index) {
    index--;
    prev = node;
    node = node->next;
  }
  count--;           // уменьшаем длину
  Node *tmp = node;  // запоминаем адрес нужного элемента
  prev->next = node->next;  // подмен€ем указатели
  node->next->prev = prev;  // мину€ текущий элемент
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
