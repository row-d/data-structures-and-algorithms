#include "dynamicarray.hpp"
#include "macros.hpp"
#include <iostream>

using std::cout;
using std::endl;

int main(int argc, char const *argv[]) {
  DynamicArray<int> array;
  array.reserve(10);
  size_t i;
  FROM0TO(i, 20) {
    cout << "size: " << array.size() << endl;
    cout << "capacity: " << array.capacity() << endl;
    cout << "pushing back : " << i << endl;
    cout << endl;
    array.push_back(i);
  }


 cout << "hola";
  return 0;
}
