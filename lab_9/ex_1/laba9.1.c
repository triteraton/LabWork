#include <stdio.h>
#include <stdlib.h>

void input_in_file(FILE, int);
void copy_f_to_f(FILE, FILE);

int main()
{
	FILE *f, *g;
	int length_f = 0; length_g = 0;

	printf("Ввидите желаемое количество чисел первого файла ( n из [20; 90]; n без остатка делится на 10)");
	scand("%d", &length_f);

	if (length_f < 20 || length_f > 90)
	{
		printf("Кол-во чисел меньше 20 или больше 90\n");
		return 1;
	}

	if (length_f % 20 != 0)
	{
		printf("Ваше кол-во чисел не кратно 20\n");
		return 1;
	}

	input_in_file(*f, n);
	copy_f_to_f(*f, g*)
	return 0;
}

void input_in_file(FILE *f, int n);
{
    int number = 0;

	printf("Начините вводить %d  чисел первого файла\n", n);
	printf("Учтите что числа должны удовлетварять следующим условиям:\n");
	printf("1: число должно быть двухзначным\n");
	printf("2: первый 10 чисел должны быть положительными, а следующие 10 отрицательными и так до %d\n", n);

	f = fopen("f.txt", w);

	for (int i = 0; i < n/10; i++)
	{
		int pos = 0;
	    for (int j = 0; j < 10; j++)
	    {

            printf("Ввод числа под номером : ", i*10+j+1);
            scanf("%d", &number);
        
            if (number > 9 || number < 100)
            {
            	fprintf(f, "%d\n", number);
            	pos++;
            }
            else if (number < -9 || number > -100)
            {
        	    fprintf(f, "%d\n", number);
        	    pos--;
            }
            else 
            {
        	    printf("Ваше число не подходит повторите \n");
        	    j--;
            }
	    }
	    if (pos != 10 && pos != -10)
	    {
	    	printf("Ваш ряд чисел прерывается числом с другим знаком\n");
	    	return 1;
	    }
	}
	fclose(f);
}

copy_f_to_f(FILE *f, FILE *g)
{
	int buf = 0;
    f = fopen("f.txt", "r");
    g = fopen("g.txt", "w");

    while (!feof(f))
    {
    	for(int i = 0; i < 5; i++)
    	{
    		fscanf(f, "%d\n", &buf);
    		fprintf(g, "%d\n", &buf);
    	}
        fseek(f, 5*4, SEEK_CUR);
        for(i = 0; i < 5; i++) 
        {
            fscanf(f, "%d\n", &y);
            fprintf(g, "%d\n", y);
        }
        fseek(f, ftell(f)-5*5-5*4, SEEK_SET);
        for(i = 0; i < 5; i++) 
        {
            fscanf(f, "%d\n", &y);
            fprintf(g, "%d\n", y);
        }
        fseek(f, 5*5, SEEK_CUR);
        for(i = 0; i < 5; i++)      
        {
            fscanf(f, "%d\n", &y);
            fprintf(g, "%d\n", y);
        }
	}

	fclose(f);
	fclose(g);
}