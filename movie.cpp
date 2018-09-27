#include "movie.h"

int Movie::getType()
{
  return 0;
}
void Movie::setAuthor(char* author, int size)
{
  for(int i = 0; i < size; i++)
    this->director[i] = author[i];
}
