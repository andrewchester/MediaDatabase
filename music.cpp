//Implementation of music.h
#include "music.h"

int Music::getType()
{
  return 1; //Return 1 since it's type music
}
//Setter for author
void Music::setAuthor(char* author, int size)
{
  for(int i = 0; i < size; i++)
    this->artist[i] = author[i];
}
