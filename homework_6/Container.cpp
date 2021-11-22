#include <iostream>
#include <vector>

#include "dblst.h"
#include "vctr.h"

using std::cout;

int main() {
  //Стираем 3,5,7 элементы
  std::vector<int> index{3, 5, 7};

  //Создали контейнер через конструктора Vec<T>()
  std::cout << "container vector type\n";
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
    contr1.remove(index.at(i) - (i + 1));
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
  cout << "\n\n";
  std::cout << "container list type\n";

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
    lst1.remove_at(index.at(i) - (i + 1));
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
  
  std::cin.get();
  return 0;
}