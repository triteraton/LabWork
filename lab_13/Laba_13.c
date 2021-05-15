#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

void enter(int*, int);
void print(int, int*);
void ShellSort(int, int*);
void deletecompact(int, int*);


int main(void)
{
    int size = 0;
    int* arr;

    printf("Enter the size of array\n");
    scanf_s("%d", &size);

    arr = (int*)malloc(size * sizeof(int));
    enter(arr, size);
    deletecompact(size, arr);
}

void enter(int* arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("Enter the element [%d] of array ", i + 1);
        scanf_s("%d", &arr[i]);
    }
}

void ShellSort(int size, int *arr)
{
    int i, j, step;
    int tmp;
    for (step = size / 2; step > 0; step /= 2)
        for (i = step; i < size; i++)
        {
            tmp = arr[i];
            for (j = i; j >= step; j -= step)
            {
                if (tmp > arr[j - step])
                    arr[j] = arr[j - step];
                else
                    break;
            }
            arr[j] = tmp;
        }
}

void deletecompact(int size, int* arr)
{
    int number = 0;
    int poss = 0;

    for (int i = 1; i < size; i++)
        for (int j = 0; j < i; j++)
        {
            if (arr[i] == arr[j])
            {
                number++;
            }
        }

    if (number != 0)
    {
        int* coliz = (int*)malloc(number * sizeof(int));
        poss = 0;

        for (int i = 1; i < size; i++)
            for (int j = 0; j < i; j++)
            {
                if (arr[i] == arr[j])
                {
                    coliz[poss++] = arr[j];
                    arr[j] = 0;
                }
            }

        int* mass = (int*)malloc(size * sizeof(int));
        poss = 0;

        for (int i = 0; i < (size - number+1); i++)
        {
            if (arr[i] != 0)
            {
                mass[poss++] = arr[i];
            }
            else continue;
        }

        free(arr);

        ShellSort((size - number), mass);
        if (number > 1)
        {
            ShellSort(number, coliz);
        }
        poss = 0;

        for (int i = (size - number); i < size; i++)
        {
            mass[i] = coliz[poss++];
        }

        free(coliz);
        print(size, mass);
    }
    else
    {
        ShellSort(size, arr);
        print(size, arr);
    }
}

void print(int size, int* arr)
{
    printf("your finished array: \n");
    for (int i = 0; i < size; i++)
    {
        printf("[%d] - %d \n ", (i + 1), arr[i]);
    }

}