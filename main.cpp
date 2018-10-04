/*
* Andrew Chester
* Media Database, Per 2
*/

#include <iostream>
#include <vector>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

#include "media.h"
#include "movie.h"
#include "videogame.h"
#include "music.h"

//Just makes a char[] lowercase, could've used towloer(), but I just copied and pasted this from a previous project
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
//Prints out the current items in media
void printArray(std::vector<Media*>* media)
{
  std::vector<Media*>::iterator it;
  for(it = media->begin(); it != media->end(); ++it)
  {
    std::cout << std::endl;
    std::cout << "Title: " << (**it).title << std::endl;
    std::cout << "  Year: " << (**it).year << std::endl;
    if((**it).getType() == 0) //0 is a movie
    {
      std::cout << "  Director: " << dynamic_cast<Movie*>(*it)->director << std::endl;
      std::cout << "  Duration: " << dynamic_cast<Movie*>(*it)->duration << std::endl;
      std::cout << "  Rating: " << dynamic_cast<Movie*>(*it)->rating << std::endl;
    }
    else if((**it).getType() == 1) //1 is Music
    {
      std::cout << "  Artist: " << dynamic_cast<Music*>(*it)->artist << std::endl;
      std::cout << "  Duration: " << dynamic_cast<Music*>(*it)->duration << std::endl;
      std::cout << "  Publisher: " << dynamic_cast<Music*>(*it)->publisher << std::endl;
    }
    else if((**it).getType() == 2) //2 is videogame
    {
      std::cout << "  Publisher: " << dynamic_cast<VideoGame*>(*it)->publisher << std::endl;
      std::cout << "  Rating: " << dynamic_cast<VideoGame*>(*it)->rating << std::endl;
    }
    std::cout << "+------------------------------------------------------------+" << std::endl;
  }
  std::cout << std::endl;
}
//Searches the array by either title or year
void searchArray(std::vector<Media*>* media)
{
  char type;
  std::cout << "Do you want to search by year or title(y/t): ";
  std::cin >> type;
  std::cin.clear();
  std::cin.ignore(100, '\n');

  bool foundResults = false;
  if(tolower(type) == 'y')//If they want to search by year
  {
    int year;
    std::cout << "Enter a year: ";
    std::cin >> year;
    std::cin.clear();
    std::cin.ignore(100, '\n');

    std::vector<Media*>::iterator it;
    for(it = media->begin(); it != media->end(); ++it)
    {
      if((**it).year == year) //When you find a year, print out results
      {
        if(!foundResults)
        {
          std::cout << "Results: ";
          foundResults = true;
        }
        std::cout << std::endl;
        std::cout << "Title: " << (**it).title << std::endl;
        std::cout << "  Year: " << (**it).year << std::endl;
        //Same as printArray, just prints out variables depending on the type of Media* 
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
    if(!foundResults) //If nothing was found
      std::cout << "We've come up with nothing!" << std::endl;
  }
  else if(tolower(type) == 't') //If they want to search by title
  {
    char title[50];
    std::cout << "Enter the title: ";
    std::cin.get(title, 50);
    std::cin.clear();
    std::cin.ignore(100, '\n');

    std::vector<Media*>::iterator it;
    for(it = media->begin(); it != media->end(); ++it)
    {
      if(strcmp((**it).title, title) == 0) //When a match is found
      {
        foundResults = true;
        std::cout << "Title: " << (**it).title << std::endl;
        std::cout << "  Year: " << (**it).year << std::endl;
        if((**it).getType() == 0) //Print out according values like before
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
      std::cout << "We've come up with nothing!" << std::endl; //In case nothing was found
  }
  else
  {
    std::cout << "Invalid input." << std::endl;
  }
}
//Adds an item to the array media
void addItem(std::vector<Media*>* media)
{
  char type[10], author[50], publisher[50],char title[50];
  int rating, year;
  float duration;

  std::cout << "Enter the type(movie, videogame, music): ";
  std::cin.get(type, 10);
  std::cin.clear();
  std::cin.ignore(100, '\n');
  makeLower(type);

  if(!(strcmp(type, "videogame") == 0 || strcmp(type, "movie") == 0 || strcmp(type, "music") == 0)) //If they enter the wrong format
  {
    std::cout << "Unrecognized media format..." << std::endl;
    return;
  }

  std::cout << "What's the title: ";
  std::cin.get(title, 50);
  std::cin.clear();
  std::cin.ignore(100, '\n');
  if(!(strcmp(type, "videogame") == 0)){ //Get author for music and movies, not videogames
    std::cout << "Who's the author: ";
    std::cin.get(author, 50);
    std::cin.clear();
    std::cin.ignore(100, '\n');
  }
  std::cout << "What year was it released? ";
  std::cin >> year;
  std::cin.clear();
  std::cin.ignore(100, '\n');

  if(strcmp(type, "movie") == 0)//Get the data for a movie from the user
  {
    std::cout << "How long is the movie? ";
    std::cin >> duration;
    std::cin.clear();
    std::cin.ignore(100, '\n');

    std::cout << "What's the rating? ";
    std::cin >> rating;
    std::cin.clear();
    std::cin.ignore(100, '\n');
	  
    //Allocate memory for a new movie object, assign the values and add it to media
    Movie* m = new Movie();

    m->rating = rating;
    m->duration = duration;
    m->year = year;
    m->setTitle(title, strlen(title));
    m->setAuthor(author, strlen(author));

    media->push_back(m);
  }
  else if(strcmp(type, "music") == 0) //Get the data for a song from user
  {
    std::cout << "How long is the song? ";
    std::cin >> duration;
    std::cin.clear();
    std::cin.ignore(100, '\n');

    std::cout << "Who's the publisher? ";
    std::cin.get(publisher, 50);
    std::cin.clear();
    std::cin.ignore(100, '\n');

    //Allocate memory for a music object, assign values, and then push to media
    Music* m = new Music();

    m->duration = duration;
    m->year = year;

    m->setTitle(title, strlen(title));
    m->setAuthor(author, strlen(author));

    media->push_back(m);
  }
  else if(strcmp(type, "videogame") == 0) //Get values for a videogame
  {
    std::cout << "Who's the publisher? ";
    std::cin.get(publisher, 50);
    std::cin.clear();
    std::cin.ignore(100, '\n');

    std::cout << "What's the rating? ";
    std::cin >> rating;
    std::cin.clear();
    std::cin.ignore(100, '\n');

    //Allocate memory for a videogame object, assign values, push to media
    VideoGame* v = new VideoGame();

    v->year = year;
    v->rating = rating;

    v->setTitle(title, strlen(title));
    v->setAuthor(publisher, strlen(publisher));

    media->push_back(v);
  }
}
//Deletes an item from media. Identical to search() except it deletes it from the array instead
//You can delete by year or title
void deleteItem(std::vector<Media*>* media)
{
  char type;
  std::cout << "Delete by year or title(y/t): ";
  std::cin >> type;
  std::cin.clear();
  std::cin.ignore(100, '\n');

  if(type == 'y') //If deleting by year
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
	//Delete the pointer and remove it from the array
        delete *it;
        media->erase(it);
	if (media->size() == 0)
	  return;
      }
    }
  }
  else if(type == 't') //If deleting by title
  {
    char title[50];
    std::cout << "Enter the title: ";
    std::cin.get(title, 50);
    std::cin.clear();
    std::cin.ignore(100, '\n');

    std::vector<Media*>::iterator it;
    for (it = media->begin(); it != media->end(); ++it)
    {
      if(strcmp((**it).title, title) == 0)
      {
	//Delete item and remove it from array
        delete *it;
	media->erase(it);
	if(media->size() == 0)
	  return;
      }
    }
  }
  else
  {
    std::cout << "Invalid input" << std::endl;
  }
}
int main()
{
  std::vector<Media*> media;
  char command[10];
  while(true)
  {
    std::cout << "Enter a command(PRINT, ADD, DELETE, SEARCH, EXIT): "; //Get the command from the user
    std::cin.get(command, 10);
    std::cin.clear();
    std::cin.ignore(100, '\n');
    makeLower(command);

    if(strcmp(command, "add") == 0)//Run additem if they type add
    {
      addItem(&media);
    }
    else if(strcmp(command, "print") == 0)//Print the array if they type print
    {
      printArray(&media);
    }
    else if(strcmp(command, "search") == 0) //Run search if they type search
    {
      searchArray(&media);
    }
    else if(strcmp(command, "delete") == 0)//Run deleteitem if they type delete
    {
      deleteItem(&media);
    }
    else if(strcmp(command, "exit") == 0)//Exit if they type exit
    {
      break;
    }
  }

  return 0;
}
