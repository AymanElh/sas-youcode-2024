#include <stdio.h>

void swap(int *a, int *b);
void triRapide(int T[], int bas, int haut);
int partition(int T[], int bas, int haut);


int main()
{
  int taille;
  printf("Entrer la taille du tableau: ");
  scanf("%d", &taille);

  int arr[taille];
  printf("Entrer les elements du tableau: \n");
  for(int i = 0; i < taille; i++)
  {
    printf("Element %d: ", i+1);
    scanf("%d", &arr[i]);
  }

  triRapide(arr, 0, taille-1);

  printf("Le tableau apres le tri est: \n");
  for(int i = 0; i < taille; i++)
  {
    printf("%d ", arr[i]);
  }
  return 0;
}

void swap(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

void triRapide(int T[], int bas, int haut)
{
  if(bas < haut)
  {
    int pivot = partition(T, bas, haut);
    triRapide(T, bas, pivot - 1);
    triRapide(T, pivot+1, haut);
  }
}

int partition(int T[], int bas, int haut)
{
  int pivot = T[haut];
  int i = bas-1;
  for(int j = bas; j < haut; j++)
  {
    if(T[j] <= pivot)
    {
      i++;
      swap(&T[i], &T[j]);
    }
  }
  swap(&T[i+1], &T[haut]);
  return i+1;
}