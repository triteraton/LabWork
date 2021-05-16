#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SIZE 3 

float arrA[SIZE][SIZE] = {{2.5, -3.12, -4.03},
                          {0.61, 0.71, -0.05},
                          {-1.03, -2.05, 0.87} };

float arrB[SIZE] = { -7.5, 0.44, -1.16};

float arrX[SIZE], arrRes[SIZE];
float beta, accuracy;

int Checker(void);
void RowSum(int, int, float, const int);
void ShowArr(const int, const int, float);
void SimpleMethod(void);
void SeidelMethod(void);
int CheckResult(void);
void menu(void);

int main()
{
    menu;

    for (int i = 0; i < SIZE; i++)
    {
        printf("x%d = %2.2f\n", i + 1, arrRes[i]);
    }

    return 0;
}

int Checker()
{
    float elementsSum = 0;
    int successCount = 0;

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (i != j)
            {
                elementsSum += fabs(arrA[i][j]);
            }
        }

        if (fabs(arrA[i][i]) > elementsSum)
        {
            successCount++;
        }

        elementsSum = 0;
    }

    if (successCount == 3)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


void RowSum(int row1, int row2, float coeff, const int columnsCount)
{
    for (int i = 0; i < columnsCount; i++)
    {
        arrA[row2][i] += arrA[row1][i] * coeff;
    }

    arrB[row2] += arrB[row1] * coeff;
}


void ShowArr(const int rows, const int columns, float matrix[rows][columns])
{
    for (int i = 0; i < rows; i++)
    {
        printf("\n");
        for (int j = 0; j < columns; j++)
        {
            printf("%2.2f%s", matrix[i][j], ((j + 1) % 3 == 0 ? "\n" : "\t"));
        }
    }
}


void SimpleMethod()
{
    float elementsSum = 0;
    static int iteration;

    if (iteration != 0)
        for (int i = 0; i < SIZE; i++)
            arrX[i] = arrRes[i];
    else
        for (int i = 0; i < SIZE; i++)
            arrX[i] = arrB[i];

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
            if (i != j) elementsSum += arrA[i][j] * arrX[j];

        arrRes[i] = (arrB[i] - elementsSum) / arrA[i][i];
        elementsSum = 0;
    }

    iteration++;
}


void SeidelMethod()
{
    float elementsSum = 0;
    static int iteration;

    if (iteration != 0)
    {
        for (int i = 0; i < SIZE; i++)
        {
            arrX[i] = arrRes[i];
        }
    }
    else
    {
        for (int i = 0; i < SIZE; i++)
        {
            arrX[i] = arrB[i];
        }
    }

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = i + 1; j < SIZE; j++)
        {
            if (i != j)
            {
                elementsSum += arrA[i][j] * arrX[j];
            }
        }

        arrRes[i] = (arrB[i] - elementsSum) / arrA[i][i];
        elementsSum = 0;

        for (int j = 0; j < i; j++)
        {
            if (i != j) 
            {
                elementsSum += arrA[i][j] * arrA[j];
            }
        }
        elementsSum /= -arrA[i][i];

        arrRes[i] += elementsSum;
        elementsSum = 0;
    }

    iteration++;
}


int CheckResult()
{
    float elementsSum = 0;

    for (int i = 0; i < SIZE; i++)
    {
        elementsSum += fabs(arrRes[i] - arrX[i]);
    }

    beta = elementsSum / SIZE;

    if (beta <= accuracy)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void menu(void)
{
    int select = 0;

    printf("Enter the required calculation accuracy: ");
    scanf("%f", &accuracy);

    RowSum(2, 0, 1, SIZE);
    RowSum(1, 0, 9, SIZE);
    RowSum(2, 1, 0.05, SIZE);
    RowSum(1, 0, -2.7, SIZE);
    RowSum(0, 1, -0.2, SIZE);

    printf("Choose the SLOUGH solution method:\n---------------------------\n1. - Simple Iteration method\n2. - Seidel method\n");

    do 
    {
        scanf_s("%d", select);
    } while (select < 1 && select > 2);

    switch (select)
    {
    case 1:
        do 
        {
            SimpleIterationMethod();
        } while (!CheckResult());
        break;

    case 2:
        do 
        {
            SeidelMethod();
        } while (!CheckResult());
        break;

    default:
        break;
    }
}