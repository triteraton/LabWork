#include<stdio.h>
#include<stdlib.h>
#include <math.h>
int main()
{
  int i;
  float a,b,c;
   i=0;
printf("ввидите числа a,b,c\n");
scanf("%f%f%f",&a, &b, &c);
  if (a>0) i++;
  if (b>0) i++;
  if (c>0) i++; 
printf("%s%d\n", "число положительных чисел равно: ",i);

}