#ifndef MEDIA_H
#define MEDIA_H

class Media
{
 public:
    //Variables
    char title[20];
    int year;

    //Virtual Functions
    virtual int getType() = 0;
    virtual void setAuthor(char* author) = 0;
    
    //Functions
    void setTitle(char* string, int size);
};
#endif
