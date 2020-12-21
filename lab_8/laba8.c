#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

struct employee {
    char surname[20];
    char name[20];
    char patronymic[20];
    char position[20];
    int birthyear;
    int salary;
};

struct employee employees[50];
int recordNumber;

// general menu
void printGeneralMenu();
// case 1
void enterEmployeeData();
//case 2
void sortingEmployeeData();
//case 3
void findEmployees();
//case 4
void editEmployees();
void editEmployee(int);
void print4Menu(int);
// case 5
void removeEmployee();
//case 6
void printEmployees(char[]);
void print6Menu();
//case 7
void exitProgram();

int main() {
    setlocale(LC_ALL, "");
    printGeneralMenu();
}

void printGeneralMenu() {
    system("clear");
    printf("Чего пожелаете, господин?\n");
    printf(" 1 - Ввод данных сотрудников;\n");
    printf(" 2 - Сортировка списка сотрудников по алфавиту;\n");
    printf(" 3 - Поиск сотрудника по заданному параметру;\n");
    printf(" 4 - Изменение параметров сотрудника;\n");
    printf(" 5 - Удаление сотрудника из массива;\n");
    printf(" 6 - Вывод сотрудников на экран;\n");
    printf(" 0 - Выход из программы.\n");
    printf("Введите номер желаемой операции: ");
    int selectedMenu;
    scanf("%d", &selectedMenu);
    switch (selectedMenu) {
        case 1: {
            enterEmployeeData();
            break;
        }
        case 2: {
            sortingEmployeeData();
            break;
        }
        case 3: {
            findEmployees();
            break;
        }
        case 4: {
            editEmployees();
            break;
        }
        case 5: {
            removeEmployee();
            break;
        }
        case 6: {
            printEmployees("");
            print6Menu();
            break;
        }
        case 0: {
            exitProgram();
            break;
        }
    }
    
    //show general menu again
    printGeneralMenu();
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
            printGeneralMenu();
            break;
        }
        case 0: {
            exitProgram();
            printEmployees("");
            print6Menu();
            break;
        }
    }
}

void enterEmployeeData() {
    // clear data array first
    memset(employees, 0, sizeof(employees));
    
    system("clear");
    printf("Введите количество сотрудников: ");
    scanf("%d", &recordNumber);
    for (int i = 0; i < recordNumber; i++) {
        printf("Введите фамилию сотрудника №%d: ", i+1);
        scanf("%s", employees[i].surname);
        printf("Введите имя сотрудника №%d: ", i+1);
        scanf("%s", employees[i].name);
        printf("Введите отчество сотрудника №%d: ", i+1);
        scanf("%s", employees[i].patronymic);
        printf("Введите должность сотрудника №%d: ", i+1);
        scanf("%s", employees[i].position);
        printf("Введите год рождения сотрудника №%d: ", i+1);
        scanf("%d", &employees[i].birthyear);
        printf("Введите заработную плату сотрудника №%d: ", i+1);
        scanf("%d", &employees[i].salary);
    }
}

void sortingEmployeeData() {
    int i, j;
    struct employee temp;
    for (i = 0; i < recordNumber-1; i++) {
        for (j = i+1; j < recordNumber; j++) {
            if (strcmp(employees[i].surname, employees[j].surname) > 0) {
                temp = employees[i];
                employees[i] = employees[j];
                employees[j] = temp;
            }
        }
    }
    printGeneralMenu();
}

void findEmployees() {
    system("clear");
    char searchLine[20];
    printf("Введите фамилию, имя, отчество или должность для поиска совпадений: ");
    scanf("%s", searchLine);
    printEmployees(searchLine);
    
    printf("\nЧего пожелаете, господин?\n");
    printf(" 1 - Поиск совпадений;\n");
    printf(" 0 - Выход в главное меню.\n");
    printf("Введите номер желаемой операции: ");
    int selectedMenu;
    scanf("%d", &selectedMenu);
    switch (selectedMenu) {
        case 1: {
            findEmployees();
            break;
        }
        case 0: {
            printGeneralMenu();
            break;
        }
    }
}

void editEmployees() {
    printEmployees("");
    int answer = 0;
    do {
        printf("\nВведите номер сотрудника, которого хотите изменить, либо введите 0 для перехода в главное меню: ");
        scanf("%d", &answer);
        if (answer == 0) {
            printGeneralMenu();
        } else if (answer > recordNumber) {
            printf("Такого номера сотрудника не существует.");
        }
    } while (answer > recordNumber);
    
    editEmployee(answer-1);
}

void editEmployee(int i) {
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
    print4Menu(i);
}

void print4Menu(int i) {
    printf("\nЧего пожелаете, господин?\n");
    printf(" 1 - Изменить фамилию;\n");
    printf(" 2 - Изменить имя;\n");
    printf(" 3 - Изменить отчество;\n");
    printf(" 4 - Изменить должность;\n");
    printf(" 5 - Изменить год рождения;\n");
    printf(" 6 - Изменить зарплату;\n");
    printf(" 9 - Выбрать другого сотрудника;\n");
    printf(" 0 - Выход в главное меню.\n");
    printf("Введите номер желаемой операции: ");
    int selectedMenu;
    scanf("%d", &selectedMenu);
    switch (selectedMenu) {
        case 1: {
            printf("Существующее значение фамилии: %s\n", employees[i].surname);
            printf("Введите новое значение фамилии: ");
            scanf("%s", employees[i].surname);
            editEmployee(i);
            break;
        }
        case 2: {
            printf("Существующее значение имени: %s\n", employees[i].name);
            printf("Введите новое значение имени: ");
            scanf("%s", employees[i].name);
            editEmployee(i);
            break;
        }
        case 3: {
            printf("Существующее значение отчества: %s\n", employees[i].patronymic);
            printf("Введите новое значение отчества: ");
            scanf("%s", employees[i].patronymic);
            editEmployee(i);
            break;
        }
        case 4: {
            printf("Существующее значение должности: %s\n", employees[i].position);
            printf("Введите новое значение должности: ");
            scanf("%s", employees[i].position);
            editEmployee(i);
            break;
        }
        case 5: {
            printf("Существующее значение года рождения: %d\n", employees[i].birthyear);
            printf("Введите новое значение года рождения: ");
            scanf("%d", &employees[i].birthyear);
            editEmployee(i);
            break;
        }
        case 6: {
            printf("Существующее значение зарплаты: %d\n", employees[i].salary);
            printf("Введите новое значение зарплаты: ");
            scanf("%d", &employees[i].salary);
            editEmployee(i);
            break;
        }
        case 9: {
            editEmployees();
            break;
        }
        case 0: {
            printGeneralMenu();
            break;
        }
    }
}

void removeEmployee() {
    printEmployees("");
    int answer = 0;
    do {
        printf("\nВведите номер сотрудника, которого хотите удалить, либо введите 0 для перехода в главное меню: ");
        scanf("%d", &answer);
        if (answer == 0) {
            printGeneralMenu();
        } else if (answer > recordNumber) {
            printf("Такого номера сотрудника не существует.");
        }
    } while (answer > recordNumber);
    
    for (int i = answer-1; i < recordNumber-1; i++) {
        employees[i] = employees[i+1];
    }
    recordNumber--;
    removeEmployee();
}

void printEmployees(char searchLine[20]) {
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

void exitProgram() {
    system("clear");
    printf("Вы действительно хотите выйти из программы? y/n: ");
    char answer = 'n';
    scanf("%s", &answer);
    if (answer == 'y') {
        // program exit
        exit(0);
    }
}