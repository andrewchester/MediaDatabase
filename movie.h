#include "media.h"
class Movie : public Media
{
  public:
    char director[20];
    float duration;
    int rating;
    int getType();
    void setAuthor(char* author);
};
