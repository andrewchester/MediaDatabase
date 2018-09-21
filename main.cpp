#include <iostream>
#include <vector>
#include <string.h>

#include "media.h"
#include "movie.h"
#include "videogame.h"
#include "music.h"

void makeLower(char* str)
{
  int asciiValue = 0;
  for(int i = 0; i < strlen(str); i++)
  {
    asciiValue = (int)str[i];
    if(asciiValue >= 65 && asciiValue <= 90)
      str[i] = (char)(asciiValue + 32);
  }
}

void addItem(std::vector<Media*>* media)
{
  char type[9];
  std::cout << "Enter the type";
}

int main()
{
  std::vector<Media*> media = new std::vector<Media*>();
  char command[10];

  std::cout << "Enter a command(PRINT, ADD, DELETE, SEARCH): ";
  std::cin.get(command, 10);
  std::cin.clear();
  std::cin.ignore(100, '\n');
  makeLower(&command);

  if(strcmp(command, "add") == 1)
  {
    addItem(&media);
  }
  
  return 0;
}
