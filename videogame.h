//Header for videogame
#include "media.h"
class VideoGame : public Media
{
  public:
    int rating;
    char publisher[50];
    int getType();
    void setAuthor(char* author, int size);
};
