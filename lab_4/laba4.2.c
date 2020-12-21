#include <stdio.h>

int numInv(int* arr,int size)
{
	int num = 0;
	for(int i = 0; i < size; i++)
	{
		for(int k = i; k < size && (i+k)< size; k++)
		{
			if(arr[i] > arr[k]) num++;
		}
	}
	return num;
}

int main(void)
{
	int arr[10], n = 10;
	printf(" ввeдите массив из 10 символов \n ");  

    for (int i = 0; i < n; i++)
    	scanf("%d",& arr[i]);
    
    printf("Число инверсий в массиве = %d\n", numInv(arr,n));

}