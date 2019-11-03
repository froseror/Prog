#include <iostream>
#include <array>
#include <iterator>

int main()
{
  int array[] = {4, 6, 7, 3, 8, 2, 1, 9, 5};
  const int numRows = std::size(array);
  
  for (int index = 0; index < numRows; ++index){
    std::cout << array[index] << "\n";
  }

  return 0;
}
