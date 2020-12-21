#include <stdio.h>
#include <math.h>


int numIncres(int num);
int isPrime(int n);


int main(void)
{
	for(int i = 10; i < 50; i++)
	{
		{
			if(numIncres(pow(i,2)) == 1 && isPrime(pow(i,2)) == 1)
			{
				printf("%s%g\n", "Это число ", pow(i,2));
				break;

			} 
		}

	}
   
	return 0;
}


int numIncres(int num)
{
	int digitalList[3];
	int k = 3;

	for (int i = 0; i < 3; ++i)
	{
		digitalList[i] = num / pow(10, k-1);
		num -= digitalList[i] * pow(10, k-1);
		k--;
	}

	if(digitalList[0] < digitalList[1] && digitalList[1] < digitalList[2])
	{
		return 1;
	}

	else return 0;

}


int isPrime(int number)
{
	if(number > 1)
	{
		for ( int i = 2; i < number; ++ i)
		{
			if((number % i) == 0) return 0;
			else return 1;
		}
	}

	return 0;
}