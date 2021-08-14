#ifndef GOLF_H  // if not defined 
#define GOLF_H  //для определения имени достаточно директивы #define с именем GOLF_H
const int Len = 40;
struct golf
{
    char fullname[Len];
    int handicap;
};

void setgolf(golf &g, const char* name, int hc);
int setgolf(golf &g);
void handicap(golf &h, int hc);
void showgolf(const golf &g);
#endif
