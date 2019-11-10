#include <iostream>
#include <math.h>     
#include <time.h>
#include <stdlib.h>

int main (int argc, char *argv[])
{
  if(argc <= 1)
  {
    std::cout << "Erro : no parameters" << std::endl;
    return 0;
  }
  
  int numberOfPlanets = atoi(argv[1]);
  
  int nameSize = log2(numberOfPlanets);

  char randomLetter[nameSize];

  int randomValue = 0;
  
  srand(time(NULL));

  int maxTime = rand() % 100000;

  std::cout << maxTime << " " << numberOfPlanets << " " << static_cast<int>(nameSize) << std::endl;

  for(int i = 0; i < numberOfPlanets; i++)
  {
    randomValue = (rand() % maxTime) + 1;

    std::cout << randomValue << " ";

    for(int j = 0; j < nameSize; j++)
    { 
      randomLetter[j] = static_cast<char>((rand()%26) + 97);

      std::cout << randomLetter[j];
    }

    std::cout << std::endl;
  }

  return 0;
}