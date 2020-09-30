#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main (void) {

	       int x,z;

	       printf("Ввидите переменную x>0:");
	       scanf("%d",&x);
	       z=16*pow(x, 2);
           printf("%s %d\n", "Ваш ответ: ", z);
}