#include "music.h"

int Music::getType()
{
  return 1;
}
void Music::setAuthor(char* author, int size)
{
  for(int i = 0; i < size; i++)
    this->artist[i] = author[i];
}
