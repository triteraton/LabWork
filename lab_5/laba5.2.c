#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

void getMatrixElements(int**, int, int);
void printMatrixElements(int*, int, int);
int maxElemRows(int**, int, int);
int maxElemCollumn(int**, int, int);
int minElemRows(int**, int, int);
int minElemCollomn(int**, int, int);
void checkSedlPoint(int*, int, int);

int main(void)
{
	int *matrix = NULL;
	int rows, cols;

	printf("%s\n", "Введите число строк матрицы: ");
	scanf("%d", &rows);

	printf("%s\n", "Введите число столбцов матрицы: ");
	scanf("%d", &cols);

	getMatrixElements(&matrix, rows, cols);
	printMatrixElements(matrix, rows, cols);
	checkSedlPoint(matrix, rows, cols);

	return 0;
}

int getMatrixIndex(int rows, int cols, int row, int col)
{
	if (row >= rows || col > cols)
	{
		return -1;
	}

	return cols * row + col;
}

void getMatrixElements(int **arr, int m, int n)
{
	*arr = (int*)calloc(m * n, sizeof(int));
	int *a = *arr;

	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			int index = getMatrixIndex(m, n, i, j);
			printf("%s %d-%d\n", "Введите элемент матрицы ", i, j);
			scanf("%d", &(a[index]));
		}
	}

	//checkSedlPoint(matrix, rows, collumn);
}

void printMatrixElements(int *arr, int m, int n)
{
	printf("\n%s\n", "Исходная матрица");
	for (int i = 0; i < m; ++i)
	{
		printf("\n");
		for (int j = 0; j < n; ++j)
		{
			int index = getMatrixIndex(m, n, i, j);
			printf("%d\t", arr[index]);
		}
		printf("\n");
	}
	printf("\n");
}

int maxElemRows(int *arr, int m, int n, int k, int l )
{
	int max = arr[getMatrixIndex(m, n, 0, 0)];
	for (int i = m; i == m; i++)
	{
		for (int j = 0; j < n; j++)
	    {
		    if (max < arr[getMatrixIndex(m, n, 0, 0)])
		    {
		    	max = arr[getMatrixIndex(m, n, 0, 0)];
	    	}
    	}
	}
	
	return max;
}

int minElemRows(int **arr, int m, int n)
{
	int min = *(arr[m]+0);
    	for(int j = 0; j < n; j++)
    	{
    		if (min > *(arr[m]+j))
    		{
    			min = *(arr[m]+j);
    		}
    	}
	return min;
}

int maxElemCollumn(int **arr, int m, int n)
{
	int max = *(arr[0]+n);
	for (int i = 0; i < m; i++)
    	for (int j = n; j == n; j++)
    	{
	    	if (max < *(arr[i]+n))
		    {
		    	max = *(arr[i]+n);
    		}
    	}
	return max;
}

int minElemCollumn(int **arr, int m, int n)
{
	int min = *(arr[0]+n);
	for (int i = 0; i < m; i++)
	    for (int j = n; j == n; j++)
	    {
		    if (min > *(arr[j]+n))
	     	{
		    	min = *(arr[j]+n);
		    }
    	}
	return min;
}

void checkSedlPoint(int *arr, int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int value = arr[getMatrixIndex(m, n, i, j)];
			
			int minInRow = (value == minElemRows(arr, i, n));
			int maxInCol = (value == maxElemCollumn(arr, m, j));

			int maxInRow = (value == maxElemRows(arr, i, n));
			int minInCol = (value == minElemCollumn(arr, m, j));

			if ((minInRow && maxInCol) || (maxInRow && minInCol))
			{
	    		printf("%s%d","седловой элемент -", *(arr[i]+j));
			}
		}
	}
}