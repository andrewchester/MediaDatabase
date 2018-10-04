//Music header
#include "media.h"
class Music : public Media
{
  public:
    float duration;
    char artist[50];
    char publisher[50];
    int getType();
    void setAuthor(char* author, int size);
};
