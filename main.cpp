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
  char type[9], author[20], publisher[20];
  char title[20];
  int rating, year;
  float duration;
  
  std::cout << "Enter the type(movie, videogame, music): ";
  std::cin.get(type, 9);
  std::cin.clear();
  std::cin.ignore(100, '\n');
  makeLower(type);

  std::cout << "What's the title: ";
  std::cin.get(title, 20);
  std::cin.clear();
  std::cin.ignore(100, '\n');
  makeLower(title);
  
  std::cout << "Who's the author: ";
  std::cin.get(author, 20);
  std::cin.clear();
  std::cin.ignore(100, '\n');
  makeLower(author);

  std::cout << "What year was it released? ";
  std::cin >> year;
  std::cin.clear();
  std::cin.ignore(100, '\n');

  if(strcmp(type, "movie") == 0)
  {
    std::cout << "How long is the movie? ";
    std::cin >> duration;
    std::cin.clear();
    std::cin.ignore(100, '\n');

    std::cout << "What's the rating? ";
    std::cin >> rating;
    std::cin.clear();
    std::cin.ignore(100, '\n');

    Movie m = Movie();
    m.setTitle(title, strlen(title));
    m.duration = duration;
    m.setAuthor(author);
    m.rating = rating;
    media->push(&m);
  }
}
int main()
{
  std::vector<Media*> media;
  char command[10];

  std::cout << "Enter a command(PRINT, ADD, DELETE, SEARCH): ";
  std::cin.get(command, 10);
  std::cin.clear();
  std::cin.ignore(100, '\n');
  makeLower(command);

  std::cout << command << std::endl;
  
  if(strcmp(command, "add") == 0)
  {
    addItem(&media);
  }
  else if(strcmp(command, "print") == 0)
  {
    std::cout << media.size() << std::endl;
  }
  
  return 0;
}
