#include <iostream>
#include <cmath>

void statistics(const double arr[], int N, double & res1, double & res2); //Add 'constant' to not  modify array in function

int main()
{

  const int N = 10;
  double data[N] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  double average, stddev; 
  statistics(data, N, average, stddev);
  
  std::cout << "The average is: " << average << "\n";
  std::cout << "The standard deviation is: " << stddev << "\n";

  return 0;
}

void statistics(const double arr[], int N, double & res1, double & res2)
{
  
  //average and standard deviation
  double sum = 0.0, sum2 = 0.0;

  for (int ii = 0; ii < N; ++ii) {
    sum += arr[ii];
    sum2 += arr[ii]*arr[ii];
  }
  
  res1 = sum/N;
  res2 = std::sqrt((sum2/N) - (res1*res1));



}
