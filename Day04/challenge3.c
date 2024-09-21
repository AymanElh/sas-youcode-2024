#include <stdio.h>

void swap(int *a, int *b);
void triSelection(int T[], int n);


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

  triSelection(arr, taille);

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

void triSelection(int T[], int n)
{
  int min_idx;
  for(int i = 0; i < n; i++)
  {
    min_idx = i;
    for(int j = i+1; j < n-1; j++)
    {
      if(T[min_idx] > T[j])
        min_idx = j;
    }
    swap(&T[i], &T[min_idx]);
  }
}