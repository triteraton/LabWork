#include <stdio.h>

int main(void){
	int i;
	float vclad,procent,endvc;

    printf("ввидите размер вклада и процент ");
    scanf("%f%f",&vclad,&procent);
    endvc=2*vclad;

	for(i=0; vclad < endvc ;i++)
	    {
		    if (vclad < endvc) 
		  	{
		        vclad += vclad*(procent/3600);
		      	printf("%s%d%s%g\n","прошло дней ",i," ваш вклад ",vclad);
		  	}
	        else if ( vclad == endvc) 
		    {
		       	printf("%s %d", "вклад удвоится через", i );
		    }
		        else 
		        {
		        	printf("%s%d%s%g\n","прошло дней ",i," ваш вклад ",vclad);
		        }
	    }
	return 0;
}