#include "media.h"

void Media::setTitle(char* string, int size)
{
  for(int i = 0; i < size; i++)
    this->title[i] = string[i];
}
