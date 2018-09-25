#include "media.h"

void setTitle(char* string, int size)
{
  for(int i = 0; i < size; i++)
    this->title = string[i];
}
