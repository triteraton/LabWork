#include<stdio.h>
#include<stdlib.h>
#include <math.h>
int main()
{
    float R,B;

    printf("ввидите радиус круга R, и сторону квадрата B:");
    scanf("%f%f",&R, &B);

    if ((2*R) >= (B * sqrt(2) ))
    {
    	printf("Можно\n");
    }
    else printf("нельзя\n");
}