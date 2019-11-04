#include <iostream>
#include <iterator>
#include <cmath>

int main()
{
  double array[] = {1.1, 1.2, 1.3, 1.4, 1.5, 1.6, 1.7, 1.8, 1.9, 1.1};
  int num = std::size(array);

  double mean = 0.0; 

  for (int ii = 0; ii < num; ++ii) {
    mean += (array[ii])/num;
  }

  double stand_dev = 0.0; 
  for (int ii = 0; ii < num; ++ii) {
  stand_dev += (array[ii] - mean)*(array[ii] - mean)/(num - 1);
  }

  stand_dev = std::sqrt(stand_dev);
    
  std::cout << "The mean is: " << mean << "\n";
  std::cout << "The standard deviation is: " << stand_dev << "\n";
  
  return 0;
}
