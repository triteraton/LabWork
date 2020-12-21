#include <stdlib.h>
#include <stdio.h>

typedef int boolean;

#define TRUE (1)
#define FALSE (0)

int getPositiveInt(void);
int getMatrixIndex(int cols, int row, int col);
int *getMatrix(int rows, int cols);
void printMatrix(int rows, int cols, int *matrix);

boolean isMaxInRow(int rows, int cols, int *matrix, int elemRow, int elemCol);
boolean isMinInRow(int rows, int cols, int *matrix, int elemRow, int elemCol);
boolean isMaxInCol(int rows, int cols, int *matrix, int elemRow, int elemCol);
boolean isMinInCol(int rows, int cols, int *matrix, int elemRow, int elemCol);

boolean isSaddlePoint(int rows, int cols, int *matrix, int pointRow, int pointCol);
void printSaddlePoints(int rows, int cols, int *matrix);


int main(void)
{
	puts("Введите кол-во строк:");
	int rows = getPositiveInt();

	puts("Введите кол-во столбцов:");
	int cols = getPositiveInt();

	puts("");

	int *matrix = getMatrix(rows, cols);
	puts("");

	puts("Матрица:");
	printMatrix(rows, cols, matrix);
	puts("");

	printSaddlePoints(rows, cols, matrix);

	return 0;
}

int getPositiveInt(void)
{
	int input = 0;
	
	do
	{
		scanf("%d", &input);
		if (input > 0) break;
		puts("Число должно быть положительным!");
	} 
	while (input <= 0);

	return input;
}

int getMatrixIndex(int cols, int row, int col)
{
	return row * cols + col;
}

int *getMatrix(int rows, int cols)
{
	int *matrix = (int*)calloc(rows * cols, sizeof(int));

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			printf("Введите элемент (%d, %d)\n", i + 1, j + 1);
			scanf("%d", &(matrix[getMatrixIndex(cols, i, j)]));
			puts("");
		}
	}
	
	return matrix;
}

void printMatrix(int rows, int cols, int *matrix)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			printf("%d\t", matrix[getMatrixIndex(cols, i, j)]);
		}
		printf("\n\n");
	}
}

boolean isMaxInRow(int rows, int cols, int *matrix, int elemRow, int elemCol)
{
	int max = matrix[getMatrixIndex(cols, elemRow, elemCol)];
	for (int i = 0; i < rows; i++)
	{
		int current = matrix[getMatrixIndex(cols, i, elemCol)];
		if (current > max)
		{
			return FALSE;
		}
	}
	return TRUE;
}

boolean isMinInRow(int rows, int cols, int *matrix, int elemRow, int elemCol)
{
	int min = matrix[getMatrixIndex(cols, elemRow, elemCol)];
	for (int i = 0; i < rows; i++)
	{
		int current = matrix[getMatrixIndex(cols, i, elemCol)];
		if (current < min)
		{
			return FALSE;
		}
	}

	return TRUE;
}

boolean isMaxInCol(int rows, int cols, int *matrix, int elemRow, int elemCol)
{
	int max = matrix[getMatrixIndex(cols, elemRow, elemCol)];
	for (int j = 0; j < cols; j++)
	{
		int current = matrix[getMatrixIndex(cols, elemRow, j)];
		if (current > max)
		{
			return FALSE;
		}
	}

	return TRUE;
}

boolean isMinInCol(int rows, int cols, int *matrix, int elemRow, int elemCol)
{
	int min = matrix[getMatrixIndex(cols, elemRow, elemCol)];
	for (int j = 0; j < cols; j++)
	{
		int current = matrix[getMatrixIndex(cols, elemRow, j)];
		if (current < min)
		{
			return FALSE;
		}
	}

	return TRUE;
}

boolean isSaddlePoint(int rows, int cols, int *matrix, int pointRow, int pointCol)
{
	boolean maxInRow = isMaxInRow(rows, cols, matrix, pointRow, pointCol);
	boolean maxInCol = isMaxInCol(rows, cols, matrix, pointRow, pointCol);

	boolean minInRow = isMinInRow(rows, cols, matrix, pointRow, pointCol);
	boolean minInCol = isMinInCol(rows, cols, matrix, pointRow, pointCol);

	return (minInRow && maxInCol) || (minInCol && maxInRow);
}

void printSaddlePoints(int rows, int cols, int *matrix)
{
	puts("Седловые точки (строка, столбец):");
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			boolean saddlePoint = isSaddlePoint(rows, cols, matrix, i, j);
			if (saddlePoint)
			{
				printf("(%d, %d)\n", i + 1, j + 1);
			}
		}
	}
}