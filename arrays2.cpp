#include <iostream>
#include <iterator> 

int main()
{
  //Get value from user:
  
  int number = 0;
  do
    {
      std::cout << "Enter an integer number between 1 and 9: ";
      std::cin >> number;

      if (std::cin.fail())
	std::cin.clear();

      std::cin.ignore(32767, '\n');
    }
  while (number < 1 or number > 9);

  //Print array:
  
    int array[] = {4, 6, 7, 3, 8, 2, 1, 9, 5};
  const int arrayLength = std::size(array);
  
  for (int index = 0; index < arrayLength; ++index){
    std::cout << array[index] << "\n";
  }

  //Print the index:

    for (int INDEX = 0; INDEX < arrayLength; ++INDEX){
      if (array[INDEX] == number){
	std::cout << "The index is: " << INDEX << std::endl;
	break;
      }
    }
    
  return 0;
}
