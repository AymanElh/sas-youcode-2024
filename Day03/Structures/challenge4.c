#include <stdio.h>

typedef struct point
{
    int x;
    int y;
}point;

int main()
{
    point p1;
    point *p = &p1;
    printf("x: ");
    scanf("%d", &p1.x);
    printf("y: ");
    scanf("%d", &p1.y);
    printf("x: %d, y: %d", p->x, p->y);
    return 0;
}