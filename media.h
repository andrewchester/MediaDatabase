#ifndef MEDIA_H
#define MEDIA_H

class Media
{
 public:
    //Variables
    char title[50];
    int year;

    //Functions
    void setTitle(char* string, int size);

    //Virtual Functions
    virtual int getType() = 0;
    virtual void setAuthor(char* author, int size) = 0;
};
#endif
