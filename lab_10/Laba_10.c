#include <stdio.h>
#include <stdlib.h>
#define N (3)
#define M (4)

double Arr[N][M] = { {0.12, -0.43, 0.14, -0.17},
		 	       {-0.07, 0.34, 0.72, 0.62},
		    	   {1.18, -0.08, -0.38, 1.12} };

//Searching for answers
void matrixOfDecision(void)
{
	double decision[M];

	decision[N - 1] = Arr[N - 1][N];
	for (int i = N - 2; i >= 0; i--)
	{
		decision[i] = Arr[i][N];
		for (int j = i + 1; j < N; j++)
		{
			decision[i] -= Arr[i][j] * decision  [j];
		}
	}
	
	for (int i = 0; i < N; i++)
	{
		printf("Unknow x[%d]= %2.3lg\n\a\a", i+1, decision[i]);
	}
}

void printMatrixElemnts(void)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			printf("%2.3lg\t\t", Arr[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void BringToTriangular(void)
{
	//bring to triangular
	for (int i = 0; i < N - 1; i++)
	{
		for (int j = i + 1; j < N; j++)
		{
			double koef = 0;
			koef = Arr[j][i] / Arr[i][i];
			for (int k = i; k < N; k++)
				Arr[j][k] -= Arr[i][k] * koef;
		}
	}

	//normalization of the coefficient matrix
	for (int k = 0; k < N; k++)
	{
		//division k row by first element
		for (int j = k; j < N; j++)
		{
			Arr[k][j] /= Arr[k][k];
		}
	}
	printf("final triangular matrix :\n");
	printMatrixElemnts();
}

int main(void)
{
	printf("Number of rows 3 \n");
	printf("Number of collumns 4\n");

	printf("Initial Extendet Matrix\n");
	printMatrixElemnts();

	BringToTriangular();
	matrixOfDecision();
	return 0;
}