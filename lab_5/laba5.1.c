#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

void getMatrixElements(int**, int, int);
void printMatrixElemnts(int**, int, int);
void rowsSums(int**, int, int);
void sortArr(int*, int);
void sortMatrixRows(int**, int*, int*, int, int);

int cpm(const void *a, const void *b)
{
	return *(int*)b - *(int*)a;
}

int main(void)
{
	int **matrix = NULL;
	int rows, collumn;

	printf("%s\n", "Введите число сторк матрицы: ");
	scanf("%d", &rows);

	printf("%s\n", "Введите число столбцов матрицы: ");
	scanf("%d", &collumn);

	getMatrixElements(matrix, rows, collumn);

	return 0;
}


void getMatrixElements(int **arr, int m, int n)
{
	arr = (int**)malloc(m * sizeof(int*));
	for (int i = 0; i < m; i++)
	{
		arr[i] = (int*)malloc(n * sizeof(int));
	}

	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			printf("%s %d-%d\n", "Введите элемент матрицы ", i, j);
			scanf("%d", arr[i]+j);
		}
	}

	printf("\n%s\n", "Исходная матрица");
	printMatrixElemnts(arr, m, n);
	rowsSums(arr, m, n);
}


void printMatrixElemnts(int **arr, int m, int n)
{
	for (int i = 0; i < m; ++i)
	{
		printf("\n");
		for (int j = 0; j < n; ++j)
		{
			printf("%d\t", *(arr[i]+j));
		}
		printf("\n");
	}
	printf("\n");
}


void rowsSums(int **arr, int m, int n)
{
	int sum = 0;
	int k = -1;
	int sumArr[m], sortSumArr[m];
	int *sa = sumArr;
	int *ssa = sortSumArr;

	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if(*(arr[i]+j) % 2 == 0 && *(arr[i]+j) < 0) sum += *(arr[i]+j);
		}

		if (sum == 0)
		{
			sumArr[i] = k;
			sortSumArr[i] = k;
			k -= 2;
		}

		else
		{
			sumArr[i] = sum;
			sortSumArr[i] = sum;
		}

		sum = 0;
	}

	sortArr(ssa, m);
	sortMatrixRows(arr, sa, ssa, m, n);
}


void sortArr(int *array, int m)
{
	qsort(array, m, sizeof(int), cpm);
	int help;
	for (int j = 0; j < m-1; j++)
	{
	    for(int i = 0; i < m; i++)
	    {
	        if(*(array+i) % 2 == -1 && i != m-1)
	        {
	            help = *(array+i+1);
	            *(array+i+1) = *(array+i);
	            *(array+i) = help;
	        }
	    }
	}
}


void sortMatrixRows(int **arr, int *sumArr, int *sortSumArr, int m, int n)
{

	int **newMatrix = NULL;
	newMatrix = (int**)malloc(m * sizeof(int*));
	for (int i = 0; i < m; i++)
	{
		newMatrix[i] = (int*)malloc(n * sizeof(int));
	}

	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if(*(sortSumArr+i) == *(sumArr+j))
			{
				for (int k = 0; k < n; ++k)
				{
					*(newMatrix[i]+k) = *(arr[j]+k);
				}
				*(sumArr+j) = 0;
				break;
			}			
		}
	}
	printf("\n%s\n", "Измененная матрица");
	printMatrixElemnts(newMatrix, m, n);
}