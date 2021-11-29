#include <iostream>
#include <vector>

#include "dblst.h"
#include "vctr.h"

using std::cout;

int main() {
  //Стираем 3,5,7 элементы
  std::vector<int> index{3, 5, 7};
 /*
 **------------------Container Vector------------
 */
  //Создали контейнер через конструктора Vec<T>()
  std::cout << "\nContainer VECTOR type\n";
  vctr<int> contr1;
  //Внесли 10 чисел метод vec.push_back()
  for (int i = 0; i < 10; i++) {
    contr1.push_back(i);
  }
  //Вывели содержимое контейнера vec.all_map()
  contr1.all_map();
  //Вывели размер
  std::cout << "size= " << contr1.size() << "\n";
  //Стерли 3,5,7 по счету элементы
  for (int i = 0; i < static_cast<int>(index.size()); i++) {
    contr1.erase(index.at(i) - (i + 1));
  };
  contr1.all_map();
  //Внесли в начало 10
  contr1.push_first(10);
  contr1.all_map();
  //Внесли в середину 20
  contr1.push_medium(20);
  contr1.all_map();
  //Внесли в конец 30
  contr1.push_back(30);
  contr1.all_map();
  //Вывели содержимое по индексу 2
  std::cout << "vector[2]= " << contr1[2] << "\n";
 /*
 **Дополнительные функции
 */
 //is_empty
 std::cout<<"Vector is Empty?\t=>\t";
 if(contr1.is_empty()){
  std::cout << "Vector is empty\n";
  }
 else{std::cout << "Vector is not empty\n";
 };
 //remove_medium удалили 20
 std::cout<<"remove_medium 20\t=>\t";
 contr1.remove_medium();
 contr1.all_map();
 //remove_front удалили 10
 std::cout<<"remove_front 10  \t=>\t";
 contr1.remove_front();
 contr1.all_map();
 // remove_back удалили 30
 std::cout<<"remove_back 30   \t=>\t";
 contr1.remove_back();
 contr1.all_map();
 
 /*
 **------------------Container list------------
 */
 cout << "\n";
 std::cout << "Container DoublyLinkedList type\n";
  ////Создали контейнер
 DBlist<int> lst1;
  ////Внесли 10 чисел
  for (int i = 0; i < 10; i++) {
    lst1.push_back(i);
  }
  ////Вывели содержимое контейнера
  lst1.all_map();
  ////Вывели размер
  std::cout << "size= " << lst1.size() << "\n";
  ////Стерли 3,5,7 по счету элементы
  for (int i = 0; i < static_cast<int>(index.size()); i++) {
    lst1.erase(index.at(i) - (i + 1));
  };
  lst1.all_map();
  //Внесли в начало 10
  lst1.push_first(10);
  lst1.all_map();
  //Внесли в середину 20
  lst1.push_medium(20);
  lst1.all_map();
  //Внесли в конец 30
  lst1.push_back(30);
  lst1.all_map();
  //Вывели содержимое по индексу 2
  std::cout << "list[2]= " << lst1[2] << "\n";
 
  /*
  *Дополнительные функции
  */
  //is_empty
  std::cout<<"DoublyLinkedList Empty?\t=>\t";
  if(lst1.is_empty()){
  std::cout << "DoublyLinkedList is empty\n";
  }
  else{std::cout << "DoublyLinkedList is not empty\n";
  };
  //remove_medium удалили 20
  std::cout<<"remove_medium 20\t=>\t";
  lst1.remove_medium();
  lst1.all_map();
  //remove_front удалили 10
  std::cout<<"remove_front 10  \t=>\t";
  lst1.remove_front();
  lst1.all_map();
  // remove_back удалили 30
  std::cout<<"remove_back 30   \t=>\t";
  lst1.remove_back();
  lst1.all_map();
return 0;
}