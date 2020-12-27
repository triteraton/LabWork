#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

struct employee 
{
    char surname[20];
    char name[20];
    char patronymic[20];
    char position[20];
    int birthyear;
    int salary;
};

struct employee employees[50];

int numberOfEmp;

void generalMenu();
void dataEntry();
void daraSort();
void dataSearch();
void dataEdit();
void editData(int);
void menuForEdit(int);
void dataDelete();
void printArr();
void print6Menu();
void Exitt();

int main(void)
{
	setlocale(LC_ALL, "Russian");
	generalMenu();
	return 0;
}

void generalMenu();
{
	system("clear");

	int item = 0;
	
	printf("Ваше действие: \n");
	printf("1 - ввод данных о сотруднике\n");
	printf("2 - сортировка списка по фамилии\n");
	printf("3 - поиск\n");
	printf("4 - редактировать\n");
	printf("5 - удалить сотрудника\n");
	printf("6 - вывод всего списка на экран\n");
	printf("0 - выход\n");
	printf("ваш выбор: \n");

	scanf("%d", &item);

	switch (item)
	{
        case 1:
        {
        	dataEntry();
        	break;
        }

        case 2:
        {
        	daraSort();
        	break;
        }

        case 3:
        {
        	dataSearch();
        	break;
        }

        case 4:
        {
        	dataEdit();
        	break;
        }

        case 5:
        {
        	dataDelete();
        	break;
        }

        case 6:
        {
        	printArr();
        	print6Menu();
        	break;
        }

        case 2020:
        {
        	printf("Под ёлкой вы нашли что-то ещё, но не то что нужно), вам надо еще немного поискать\n");
        	break;
        }

        case 0:
        {
        	Exitt()
        	break;
        }
	}
}

void dataEntry()
{
	memset(employees, 0, sizeof(employees));
    
    system("clear");

    printf("Введите количество сотрудников: ");
    scanf("%d", &numberOfEmp);

    for (int i = 0; i < numberOfEmp; i++)
    {
    	printf("Введите фамилью работника: ");
        scanf("%s\n", employees[i].surname);    

        printf("Введите имя работника: ");
        scanf("%s\n", employees[i].name);  

        printf("Введите отчество работника: ");
        scanf("%s\n", employees[i].patronymic);  

        printf("Введите должность работника: ");
        scanf("%s\n", employees[i].position);  

        printf("Введите год рождения работника: ");
        scanf("%s\n", employees[i].birthyear);  

        printf("Введите заработная плата работника: ");
        scanf("%s\n", employees[i].salary);  	
    }
}

void daraSort();
{
    struct employee temp;

    for (int i = 0; i < numberOfEmp-1; i++) 
    {
        for (int j = i+1; j < numberOfEmp; j++) 
        {
            if (strcmp(employees[i].surname, employees[j].surname) > 0) 
            {
                temp = employees[i];
                employees[i] = employees[j];
                employees[j] = temp;
            }
        }
    }

    generalMenu();
}

void dataSearch() {
    system("clear");
    char searchLine[20];
    
    printf("Введите фамилию, имя, отчество, должность для поиска совпадений: ");
    scanf("%s", searchLine);
    printArr(searchLine);
    
    printf("\nВаше действие\n");
    printf(" 1 - Поиск по другому пораметру;\n");
    printf(" 0 - Выход в главное меню.\n");
    printf("Введите номер желаемой операции: ");

    int item;
    scanf("%d", &item);
    switch (item) 
    {
        case 1:
        {
            dataSearch();
            break;
        }
        case 0: 
        {
            generalMenu();
            break;
        }
        case 2020: 
        {
            printf("я думаю что ключ ко всему это OAIP \n");
        }
    }
}

void dataEdit() 
{
    editData("");

    int answer = 0;
    do {
        printf("\nВведите номер сотрудника, которого хотите изменить, либо введите 0 для перехода в главное меню: ");
        scanf("%d", &answer);
        if (answer == 0) {
            printGeneralMenu();
        } else if (answer > numberOfEmp) {
            printf("Такого номера сотрудника не существует.");
        }
    } while (answer > numberOfEmp);
    
    editData(answer-1);
}

void editData(int i)
{
    system("clear");

    printf("╔════╦══════════════════════╦══════════════════════╦══════════════════════╦══════════════════════╦══════════════╦════════════╗\n");
    printf("║  № ║ Фамилия              ║ Имя                  ║ Отчество             ║ Должность            ║ Год рождения ║   Зарплата ║\n");
    printf("╠════╬══════════════════════╬══════════════════════╬══════════════════════╬══════════════════════╬══════════════╬════════════╣\n");
    printf("║ %2d ║ %-20.20s ║ %-20.20s ║ %-20.20s ║ %-20.20s ║ %12d ║ %10d ║\n",
        i+1,
        employees[i].surname,
        employees[i].name,
        employees[i].patronymic,
        employees[i].position,
        employees[i].birthyear,
        employees[i].salary
    );
    printf("╚════╩══════════════════════╩══════════════════════╩══════════════════════╩══════════════════════╩══════════════╩════════════╝\n");

    menuForEdit(i);
}

void menuForEdit(int i) {
    printf("\nЧто хотите изменить?\n");

    printf(" 1 - фамилию;\n");
    printf(" 2 - имя;\n");
    printf(" 3 - отчество;\n");
    printf(" 4 - должность;\n");
    printf(" 5 - год рождения;\n");
    printf(" 6 - зарплату;\n");
    printf("Если не хотите ничего менять выберите следующий из вариантов:\n");
    printf(" 9 - Выбрать другого сотрудника;\n");
    printf(" 0 - Выход в главное меню.\n");
    printf("Введите номер желаемой операции: ");

    int selectedMenu;
    scanf("%d", &selectedMenu);

    switch (selectedMenu) 
    {
        case 1: 
        {
            printf("Существующее значение фамилии: %s\n", employees[i].surname);
            printf("Введите новое значение фамилии: ");
            scanf("%s", employees[i].surname);
            editdata(i);
            break;
        }
        case 2: 
        {
            printf("Существующее значение имени: %s\n", employees[i].name);
            printf("Введите новое значение имени: ");
            scanf("%s", employees[i].name);
            editdata(i);
            break;
        }
        case 3: 
        {
            printf("Существующее значение отчества: %s\n", employees[i].patronymic);
            printf("Введите новое значение отчества: ");
            scanf("%s", employees[i].patronymic);
            editdata(i);
            break;
        }
        case 4: 
        {
            printf("Существующее значение должности: %s\n", employees[i].position);
            printf("Введите новое значение должности: ");
            scanf("%s", employees[i].position);
            editdata(i);
            break;
        }
        case 5: 
        {
            printf("Существующее значение года рождения: %d\n", employees[i].birthyear);
            printf("Введите новое значение года рождения: ");
            scanf("%d", &employees[i].birthyear);
            editdata(i);
            break;
        }
        case 6: 
        {
            printf("Существующее значение зарплаты: %d\n", employees[i].salary);
            printf("Введите новое значение зарплаты: ");
            scanf("%d", &employees[i].salary);
            editdata(i);
            break;
        }
        case 9: 
        {
            dataEdit();
            break;
        }
        case 0: 
        {
            generalMenu();
            break;
        }
    }
}

void dataDelete() {
    printArr("");
    int answer = 0;
    do {
        printf("\nВведите номер сотрудника, которого хотите удалить, либо введите 0 для перехода в главное меню: ");
        scanf("%d", &answer);
        if (answer == 0) {
            generalMenu();
        } else if (answer > recordNumber) {
            printf("Такого номера сотрудника не существует.");
        }
    } while (answer > recordNumber);
    
    for (int i = answer-1; i < recordNumber-1; i++) {
        employees[i] = employees[i+1];
    }
    recordNumber--;
    dataDelete();
}

void printArr(char searchLine[20]) {
    system("clear");
    int i;
    struct employee tempEmployees[50];
    int tempRecordNumber = 0;
    for (i = 0; i < recordNumber; i++) {
        if (
            searchLine == "" ||
            strstr(employees[i].surname, searchLine) ||
            strstr(employees[i].name, searchLine) ||
            strstr(employees[i].patronymic, searchLine) ||
            strstr(employees[i].position, searchLine)
        ) {
            tempEmployees[tempRecordNumber] = employees[i];
            tempRecordNumber++;
        }
    }
    
    printf("╔════╦══════════════════════╦══════════════════════╦══════════════════════╦══════════════════════╦══════════════╦════════════╗\n");
    printf("║  № ║ Фамилия              ║ Имя                  ║ Отчество             ║ Должность            ║ Год рождения ║   Зарплата ║\n");
    printf("╠════╬══════════════════════╬══════════════════════╬══════════════════════╬══════════════════════╬══════════════╬════════════╣\n");
    for (i = 0; i < tempRecordNumber; i++) {
        printf("║ %2d ║ %-20.20s ║ %-20.20s ║ %-20.20s ║ %-20.20s ║ %12d ║ %10d ║\n",
            i+1,
            tempEmployees[i].surname,
            tempEmployees[i].name,
            tempEmployees[i].patronymic,
            tempEmployees[i].position,
            tempEmployees[i].birthyear,
            tempEmployees[i].salary
        );
        if (i+1 < tempRecordNumber) {
            printf("╟────╫──────────────────────╫──────────────────────╫──────────────────────╫──────────────────────╫──────────────╫────────────╢\n");
        }
    }
    printf("╚════╩══════════════════════╩══════════════════════╩══════════════════════╩══════════════════════╩══════════════╩════════════╝\n");
}

void print6Menu() {
    printf("\nЧего пожелаете, господин?\n");
    printf(" 1 - Выход в главное меню;\n");
    printf(" 0 - Выход из программы.\n");
    printf("Введите номер желаемой операции: ");
    int selectedMenu;
    scanf("%d", &selectedMenu);
    switch(selectedMenu) {
        case 1: {
            generalMenu();
            break;
        }
        case 0: {
            Exit();
            printArr("");
            print6Menu();
            break;
        }
    }
}

void Exit();
{
	system("clear");
	int num = 0;
	
	printf("Вы действительно хотите выйти?\n (1-да, 0- нет)");
	scanf("%d", &num);

	if(num == 1)
	{
		exit(0);
	}
	else if(num == 0)
	{
        generalMenu();
	}
	else
	{
		printf("вы что-то напутали шифр AES U2FsdGVkX1/FAaqmDYyHQfgPhJB5V4d+m0fFHQKtEvos6BW1mgi59ynxtXIWE/8qA77fED3WYm8PIUEoa+JaVA==\n ЭКСТРЕННОЕ ВОЗВРАЩЕНИЕ В ГЛАВНОЕ МЕНЮ!", );
		//printf("если вы это заметили то значит приманка сработала\n");
		generalMenu();
	}
}