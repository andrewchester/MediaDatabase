#include <iostream>

#include "media.h"
#include "movie.h"
#include "videogame.h"
#include "music.h"


int main()
{
  char sampleText[1024 * 1024];
  Movie m;
  std::cout << m.getType() << std::endl;
  return 0;
}
