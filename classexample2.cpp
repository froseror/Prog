#include <iostream>
#include <cmath>

int main()
{

  const int N = 10;
  double data[N] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  //average and standard deviation
  double sum = 0.0, sum2 = 0.0;
  for (int ii = 0; ii < N; ++ii) {
    sum += data[ii];
    sum2 += data[ii]*data[ii];
  }

  double average = sum/N;
  double stddev = std::sqrt((sum2/N) - (average*average));

  std::cout << "The average is: " << average << "\n";
  std::cout << "The standard deviation is: " << stddev << "\n";
  
  return 0;
}
