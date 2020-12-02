#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main (void) {

	       float x,y,z,S,Q,W;

	         printf("Переменная x, y ,z:");
	         scanf("%f%f%f",&x,&y,&z);
              Q=cbrt(9+pow((x-y),2))/(pow(x,2)+pow(y,2)+2);
              W=exp(fabs(x-y))*pow(tan(z),3);
              S=Q-W;
           printf("%s %f\n", "Ваш ответ: ", S);
            return 0;
}