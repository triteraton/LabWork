#include <stdlib.h>
#include <stdio.h>
#include <math.h>

float main (void) {

	       float x,y,z,S;

	         printf("Переменная x, y ,z:");
	         scanf("%f%f%f",&x,&y,&z);
	       S= pow(9+pow((x-y),2),1/3)/(pow(x,2)+pow(y,2)+2)-exp(fabs(x-y))*pow(tan(z),3);
           printf("%s %f\n", "Ваш ответ: ", S);
}