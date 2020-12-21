#include <stdio.h>
#include <locale.h>


void removeSpace(char[102]);
void printString(char[102]);

int main(void)
{
	setlocale(LC_ALL, "Russian");

	char userString[102] = {};

	printf("%s\n", "Введите строку не более 100 символов: ");
	fgets(userString, sizeof(userString), stdin);

    removeSpace(userString);

    printf("Готовая строка : %s", userString);

	return 0;
}

void removeSpace(char string[102])
{
    for (int i = 0; i < 102; i++) 
    {
        if (string[i] == ' ' && string[i+1] == ' ') 
        {
            for (int j = i + 1; j < 102; j++) 
            {
                string[j] = string[j+1];
            }
            i--;
        }
    }
}