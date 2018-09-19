#ifndef MEDIA_H
#define MEDIA_H

class Media
{
 public:
    //Variables
    char title[20];
    int year;

    //Functions
    virtual int getType() = 0;
};
#endif
