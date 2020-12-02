#include <stdio.h>

void revers(int* nArr, int size)
{
  for (int i = 0, j = size-1; i<j; i++, j--)
  {
    int buf = nArr[i];
    nArr[i]= nArr[j];
    nArr[j]= buf;
  }
}


int main(void)
{

  int arr[10];	
  int n = 10;
  printf(" ввeдите массив из 10 символов \n ");
  
  for (int i = 0; i < n; i++)
  {
    scanf("%d",& arr[i]);
  }

  revers(arr,n);

  for (int i = 0; i < n; i++)
  {
    printf("%d\t",arr[i]);
  }
  
  printf("\n");
}


