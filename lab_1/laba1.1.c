#include <math.h>
#include <stdlib.h>
#include <stdio.h>

int main (void) {

	       int x,z;

	       printf("Ввидите переменную x:");
	       scanf("%d",&x);
	       z=16*pow(x, 2);
           printf("%s %d\n", "Ваш ответ: ", z);
}