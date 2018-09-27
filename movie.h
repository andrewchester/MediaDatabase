#include "media.h"
class Movie : public Media
{
  public:
    char director[50];
    float duration;
    int rating;

    int getType();
    void setAuthor(char* author, int size);
};
