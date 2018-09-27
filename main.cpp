#include <iostream>
#include <vector>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

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
void printArray(std::vector<Media*>* media)
{
  std::vector<Media*>::iterator it;
  for(it = media->begin(); it != media->end(); ++it)
  {
    std::cout << std::endl;
    std::cout << "Title: " << (**it).title << std::endl;
    std::cout << "  Year: " << (**it).year << std::endl;
    if((**it).getType() == 0)
    {
      std::cout << "  Director: " << dynamic_cast<Movie*>(*it)->director << std::endl;
      std::cout << "  Duration: " << dynamic_cast<Movie*>(*it)->duration << std::endl;
      std::cout << "  Rating: " << dynamic_cast<Movie*>(*it)->rating << std::endl;
    }
    else if((**it).getType() == 1)
    {
      std::cout << "  Artist: " << dynamic_cast<Music*>(*it)->artist << std::endl;
      std::cout << "  Duration: " << dynamic_cast<Music*>(*it)->duration << std::endl;
      std::cout << "  Publisher: " << dynamic_cast<Music*>(*it)->publisher << std::endl;
    }
    else if((**it).getType() == 2)
    {
      std::cout << "  Publisher: " << dynamic_cast<VideoGame*>(*it)->publisher << std::endl;
      std::cout << "  Rating: " << dynamic_cast<VideoGame*>(*it)->rating << std::endl;
    }
    std::cout << "+------------------------------------------------------------+" << std::endl;
  }
}
void searchArray(std::vector<Media*>* media)
{
  char type;
  std::cout << "Do you want to search by year or title(y/t): ";
  std::cin >> type;
  std::cin.clear();
  std::cin.ignore(100, '\n');

  bool foundResults = false;
  if(tolower(type) == 'y')
  {
    int year;
    std::cout << "Enter a year: ";
    std::cin >> year;
    std::cin.clear();
    std::cin.ignore(100, '\n');
    
    std::vector<Media*>::iterator it;
    for(it = media->begin(); it != media->end(); ++it)
    {
      if((**it).year == year)
      {
        if(!foundResults)
        {
          std::cout << "Results: ";
          foundResults = true;
        }
        std::cout << std::endl;
        std::cout << "Title: " << (**it).title << std::endl;
        std::cout << "  Year: " << (**it).year << std::endl;
        if((**it).getType() == 0)
        {
          std::cout << "  Director: " << dynamic_cast<Movie*>(*it)->director << std::endl;
          std::cout << "  Duration: " << dynamic_cast<Movie*>(*it)->duration << std::endl;
          std::cout << "  Rating: " << dynamic_cast<Movie*>(*it)->rating << std::endl;
        }
        else if((**it).getType() == 1)
        {
          std::cout << "  Artist: " << dynamic_cast<Music*>(*it)->artist << std::endl;
          std::cout << "  Duration: " << dynamic_cast<Music*>(*it)->duration << std::endl;
          std::cout << "  Publisher: " << dynamic_cast<Music*>(*it)->publisher << std::endl;
        }
        else if((**it).getType() == 2)
        {
          std::cout << "  Publisher: " << dynamic_cast<VideoGame*>(*it)->publisher << std::endl;
          std::cout << "  Rating: " << dynamic_cast<VideoGame*>(*it)->rating << std::endl;
        }
        std::cout << "+------------------------------------------------------------+" << std::endl;
      }
    }
    if(!foundResults)
      std::cout << "We've come up with nothing!" << std::endl;
  }
  else if(tolower(type) == 't')
  {
    char title[50];
    std::cout << "Enter the title: ";
    std::cin.get(title, 50);
    std::cin.clear();
    std::cin.ignore(100, '\n');

    std::vector<Media*>::iterator it;
    for(it = media->begin(); it != media->end(); ++it)
    {
      if(strcmp((**it).title, title) == 0)
      {
        foundResults = true;
        std::cout << "Title: " << (**it).title << std::endl;
        std::cout << "  Year: " << (**it).year << std::endl;
        if((**it).getType() == 0)
        {
          std::cout << "  Director: " << dynamic_cast<Movie*>(*it)->director << std::endl;
          std::cout << "  Duration: " << dynamic_cast<Movie*>(*it)->duration << std::endl;
          std::cout << "  Rating: " << dynamic_cast<Movie*>(*it)->rating << std::endl;
        }
        else if((**it).getType() == 1)
        {
          std::cout << "  Artist: " << dynamic_cast<Music*>(*it)->artist << std::endl;
          std::cout << "  Duration: " << dynamic_cast<Music*>(*it)->duration << std::endl;
          std::cout << "  Publisher: " << dynamic_cast<Music*>(*it)->publisher << std::endl;
        }
        else if((**it).getType() == 2)
        {
          std::cout << "  Publisher: " << dynamic_cast<VideoGame*>(*it)->publisher << std::endl;
          std::cout << "  Rating: " << dynamic_cast<VideoGame*>(*it)->rating << std::endl;
        }
        std::cout << "+------------------------------------------------------------+" << std::endl;
      }
    }
    if(!foundResults)
      std::cout << "We've come up with nothing!" << std::endl;
  }
}
void addItem(std::vector<Media*>* media)
{
  char type[10], author[50], publisher[50];
  char title[50];
  int rating, year;
  float duration;

  std::cout << "Enter the type(movie, videogame, music): ";
  std::cin.get(type, 10);
  std::cin.clear();
  std::cin.ignore(100, '\n');
  makeLower(type);

  if(!(strcmp(type, "videogame") == 0 || strcmp(type, "movie") == 0 || strcmp(type, "music") == 0))
  {
    std::cout << "Unrecognized media format..." << std::endl;
    return;
  }

  std::cout << "What's the title: ";
  std::cin.get(title, 50);
  std::cin.clear();
  std::cin.ignore(100, '\n');
  if(!(strcmp(type, "videogame") == 0)){
    std::cout << "Who's the author: ";
    std::cin.get(author, 50);
    std::cin.clear();
    std::cin.ignore(100, '\n');
  }
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

    Movie* m = new Movie();

    m->rating = rating;
    m->duration = duration;
    m->year = year;
    m->setTitle(title, strlen(title));
    m->setAuthor(author, strlen(author));

    media->push_back(m);
  }
  else if(strcmp(type, "music") == 0)
  {
    std::cout << "How long is the song? ";
    std::cin >> duration;
    std::cin.clear();
    std::cin.ignore(100, '\n');

    std::cout << "Who's the publisher? ";
    std::cin.get(publisher, 50);
    std::cin.clear();
    std::cin.ignore(100, '\n');

    Music* m = new Music();

    m->duration = duration;
    m->year = year;

    m->setTitle(title, strlen(title));
    m->setAuthor(author, strlen(author));

    media->push_back(m);
  }
  else if(strcmp(type, "videogame") == 0)
  {
    std::cout << "Who's the publisher? ";
    std::cin.get(publisher, 50);
    std::cin.clear();
    std::cin.ignore(100, '\n');

    std::cout << "What's the rating? ";
    std::cin >> rating;
    std::cin.clear();
    std::cin.ignore(100, '\n');

    VideoGame* v = new VideoGame();

    v->year = year;
    v->rating = rating;

    v->setTitle(title, strlen(title));
    v->setAuthor(publisher, strlen(publisher));

    media->push_back(v);
  }
}
void delete()
{
  char type;
  std::cout << "Delete by year or title(y/t): ";
  std::cin >> type;
  std::cin.clear();
  std::cin.ignore(100, '/n');

  if(type == 'y')
  {
    int year;
    std::cout << "Enter the year: ";
    std::cin >> year;
    std::cin.clear();
    std::cin.ignore(100, '\n');

    std::vector<Media*>::iterator it;
    for(it = media->begin(); it != media->end(); ++it)
    {
      if((**it).year == year)
      {
	
      }
    }
  }
}
int main()
{
  std::vector<Media*> media;
  char command[10];
  while(true)
  {
    std::cout << "Enter a command(PRINT, ADD, DELETE, SEARCH, EXIT): ";
    std::cin.get(command, 10);
    std::cin.clear();
    std::cin.ignore(100, '\n');
    makeLower(command);

    if(strcmp(command, "add") == 0)
    {
      addItem(&media);
    }
    else if(strcmp(command, "print") == 0)
    {
      printArray(&media);
    }
    else if(strcmp(command, "search") == 0)
    {
      searchArray(&media);
    }
    else if(strcmp(command, "exit") == 0)
    {
      break;
    }
  }

  return 0;
}
