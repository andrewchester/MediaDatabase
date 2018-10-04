//Implementation of videogame.h
#include "videogame.h"

int VideoGame::getType()
{
  return 2;//Return 2 since it's type videogame
}
//Setter for author(really publisher since its a videogame)
void VideoGame::setAuthor(char* author, int size)
{
  for(int i = 0; i < size; i++)
    this->publisher[i] = author[i];
}
