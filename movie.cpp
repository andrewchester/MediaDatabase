//Implementation of movie.h
#include "movie.h"

int Movie::getType()
{
  return 0; //Return 0 since it's type movie
}
//Setter for author
void Movie::setAuthor(char* author, int size)
{
  for(int i = 0; i < size; i++)
    this->director[i] = author[i];
}
