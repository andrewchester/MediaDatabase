#include "videogame.h"

int VideoGame::getType()
{
  return 2;
}
void VideoGame::setAuthor(char* author, int size)
{
  for(int i = 0; i < size; i++)
    this->publisher[i] = author[i];
}
