#include <stdio.h>

void swap(int *a, int *b);
void triInsertion(int T[], int n);


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

  triInsertion(arr, taille);

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

void triInsertion(int T[], int n)
{
  for(int i = 0; i < n; i++)
  {
    int temp = T[i];
    int j = i - 1;
    while(temp < T[j] && j >= 0)
    {
      T[j+1] = T[j];
      j--;
    }
    T[j+1] = temp;
  }
}