#include <iostream>
#include <iterator>

int main()
{

  int scores[] = {84, 92, 76, 81, 56};
  const int numStudents = std::size(scores);
  
  int maxIndex = 0;

  for (int student = 0; student < numStudents; ++student){
    if (scores[student] > scores[maxIndex])
      maxIndex = student;
  }

  std::cout << "The index of the best score is: " << maxIndex << std::endl;

    return 0;
  }
