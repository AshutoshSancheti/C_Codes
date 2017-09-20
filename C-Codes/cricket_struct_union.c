#include <stdio.h>

#define MAX 30

typedef char countryName[MAX];

typedef struct
{
    countryName name;
    int age;
    float bat_avg;
}batsman;

typedef struct
{
    countryName name;
    int age;
    float bowl_avg;
}bowler;

typedef struct
{
    countryName name;
    int age;
    int no_of_catches;
}wicketkeeper;

typedef enum{BOWLER = -1, WICKETKEEPER, BATSMAN}playerkind;

typedef struct
{
    playerkind kind;

    union
    {
        batsman Batsman;
        bowler Bowler;
        wicketkeeper Wicketkeeper;
    }playertype;
}player;













