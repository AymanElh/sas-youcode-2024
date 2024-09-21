#include <stdio.h>

typedef struct rectangle
{
    float longeur;
    float largeur;
}rectangle;

float air(rectangle r1);

int main()
{
    rectangle r = {12, 23};
    printf("Air de r est: %.2f", air(r));
    return 0;
}

float air(rectangle r1)
{
    return r1.largeur * r1.longeur;
}