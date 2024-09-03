#include <stdio.h>

int main()
{
    float m_s, km_h;

    printf("Entrer la vitesse en km/H: ");
    scanf("%f", &km_h);

    m_s = km_h * 0.27778;

    printf("La vitesse en m_s: %.2f", m_s);
    return 0;
}