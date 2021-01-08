#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

FILE *S1, *TEMPS1;
char S1_NAME[] = "S1.txt";
char TEMPS1_NAME[] = "TEMPS1.txt";

struct employee {
    char surname[20];
    char name[20];
    char patronymic[20];
    char position[20];
    int birthyear;
    int salary;
};

long EMPLOYEE_SIZE = sizeof(struct employee);

// general menu
void printGeneralMenu(char[]);
// case 1
void enterEmployeeData();
//case 2
void sortingEmployeeData();
//case 3
void findEmployees();
//case 4
void editEmployees();
void editEmployee(int);
void print4Menu(int, struct employee);
void editEmployeeInFile(int, struct employee);
// case 5
void removeEmployee();
//case 6
int printEmployees(char[]);
void print6Menu();
//case 7
void exitProgram();

int freadSafe(struct employee *, FILE *);
int fwriteSafe(struct employee *, FILE *);

int main() {
    setlocale(LC_ALL, "UTF-8");
    printGeneralMenu("");
}

void printGeneralMenu(char errorMessage[]) {
    system("cls");
    if (errorMessage != "") {
        printf("%s\n\n", errorMessage);
    }
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
    printGeneralMenu("");
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
            printGeneralMenu("");
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
    struct employee empl;
    system("cls");
    if ((S1 = fopen(S1_NAME, "ab")) == NULL) {
        printGeneralMenu("Файл не найден.");
    } else {
        char answer = 'n';
        do {
            printf("Введите фамилию сотрудника: ");
            scanf("%s", empl.surname);
            printf("Введите имя сотрудника: ");
            scanf("%s", empl.name);
            printf("Введите отчество сотрудника: ");
            scanf("%s", empl.patronymic);
            printf("Введите должность сотрудника: ");
            scanf("%s", empl.position);
            printf("Введите год рождения сотрудника: ");
            scanf("%d", &empl.birthyear);
            printf("Введите заработную плату сотрудника: ");
            scanf("%d", &empl.salary);
            fwriteSafe(&empl, S1);
            system("cls");
            printf("Желаете ввести ещё одного сотрудника? y/n: ");
            scanf("%s", &answer);
        } while (answer == 'y');
    }
    fclose(S1);
}

void sortingEmployeeData() {
    struct employee empl1, empl2;
    if ((S1 = fopen(S1_NAME, "r+b")) == NULL) {
        printGeneralMenu("Файл не найден.");
    } else {
        int j, i = 0;
        int isNotEOF = 0;
        while (freadSafe(&empl1, S1) == 1) {
            j = i + 1;
            while ((isNotEOF = freadSafe(&empl2, S1)) == 1) {
                if (strcmp(empl1.surname, empl2.surname) > 0) {
                    fseek(S1, EMPLOYEE_SIZE*i, SEEK_SET);
                    fwriteSafe(&empl2, S1);
                    fseek(S1, EMPLOYEE_SIZE*j, SEEK_SET);
                    fwriteSafe(&empl1, S1);
                    empl1 = empl2;
                    fseek(S1, EMPLOYEE_SIZE*(j+1), SEEK_SET);
                }
                j++;
            }
            i++;
            if (!isNotEOF) {
                fseek(S1, EMPLOYEE_SIZE*i, SEEK_SET);
            }
        }
    }
    fclose(S1);
}

void findEmployees() {
    system("cls");
    char searchLine[20];
    printf("Введите фамилию, имя, отчество, должность, год рождения или зарплату для поиска совпадений: ");
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
            // print general menu
            break;
        }
    }
}

void editEmployees() {
    int recordNumber = printEmployees("");
    int answer = 0;
    do {
        printf("\nВведите номер сотрудника, которого хотите изменить, либо введите 0 для перехода в главное меню: ");
        scanf("%d", &answer);
        if (answer == 0) {
            printGeneralMenu("");
        } else if (answer > recordNumber) {
            printf("Такого номера сотрудника не существует.");
        }
    } while (answer > recordNumber);

    editEmployee(answer-1);
}

void editEmployee(int i) {
    system("cls");
    if ((S1 = fopen(S1_NAME, "rb")) == NULL) {
        printGeneralMenu("Файл не найден.");
    } else {
        fseek(S1, EMPLOYEE_SIZE*i, SEEK_SET);
        struct employee tempEmployee;
        freadSafe(&tempEmployee, S1);
        printf("╔════╦══════════════════════╦══════════════════════╦══════════════════════╦══════════════════════╦══════════════╦════════════╗\n");
        printf("║  № ║ Фамилия              ║ Имя                  ║ Отчество             ║ Должность            ║ Год рождения ║   Зарплата ║\n");
        printf("╠════╬══════════════════════╬══════════════════════╬══════════════════════╬══════════════════════╬══════════════╬════════════╣\n");
        printf("║ %2d ║ %-20.20s ║ %-20.20s ║ %-20.20s ║ %-20.20s ║ %12d ║ %10d ║\n",
            i+1,
            tempEmployee.surname,
            tempEmployee.name,
            tempEmployee.patronymic,
            tempEmployee.position,
            tempEmployee.birthyear,
            tempEmployee.salary
        );
    printf("╚════╩══════════════════════╩══════════════════════╩══════════════════════╩══════════════════════╩══════════════╩════════════╝\n");
        print4Menu(i, tempEmployee);
    }
    fclose(S1);
}

void print4Menu(int i, struct employee empl) {
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
            printf("Существующее значение фамилии: %s\n", empl.surname);
            printf("Введите новое значение фамилии: ");
            scanf("%s", empl.surname);
            editEmployeeInFile(i, empl);
            editEmployee(i);
            break;
        }
        case 2: {
            printf("Существующее значение имени: %s\n", empl.name);
            printf("Введите новое значение имени: ");
            scanf("%s", empl.name);
            editEmployeeInFile(i, empl);
            editEmployee(i);
            break;
        }
        case 3: {
            printf("Существующее значение отчества: %s\n", empl.patronymic);
            printf("Введите новое значение отчества: ");
            scanf("%s", empl.patronymic);
            editEmployeeInFile(i, empl);
            editEmployee(i);
            break;
        }
        case 4: {
            printf("Существующее значение должности: %s\n", empl.position);
            printf("Введите новое значение должности: ");
            scanf("%s", empl.position);
            editEmployeeInFile(i, empl);
            editEmployee(i);
            break;
        }
        case 5: {
            printf("Существующее значение года рождения: %d\n", empl.birthyear);
            printf("Введите новое значение года рождения: ");
            scanf("%d", &empl.birthyear);
            editEmployeeInFile(i, empl);
            editEmployee(i);
            break;
        }
        case 6: {
            printf("Существующее значение зарплаты: %d\n", empl.salary);
            printf("Введите новое значение зарплаты: ");
            scanf("%d", &empl.salary);
            editEmployeeInFile(i, empl);
            editEmployee(i);
            break;
        }
        case 9: {
            editEmployees();
            break;
        }
        case 0: {
            // print general menu
            break;
        }
    }
}
void editEmployeeInFile(int i, struct employee empl) {
    if ((S1 = fopen(S1_NAME, "r+b")) == NULL) {
        printGeneralMenu("Файл не найден.");
    } else {
        fseek(S1, EMPLOYEE_SIZE*i, SEEK_SET);
        fwriteSafe(&empl, S1);
    }
    fclose(S1);
}

void removeEmployee() {
    int recordNumber = printEmployees("");
    int answer = 0;
    do {
        printf("\nВведите номер сотрудника, которого хотите удалить, либо введите 0 для перехода в главное меню: ");
        scanf("%d", &answer);
        if (answer == 0) {
            printGeneralMenu("");
        } else if (answer > recordNumber) {
            printf("Такого номера сотрудника не существует.");
        }
    } while (answer > recordNumber);
    struct employee tempEmployee;
    if ((S1 = fopen(S1_NAME, "rb")) == NULL) {
        printGeneralMenu("Файл не найден.");
    } else {
        TEMPS1 = fopen(TEMPS1_NAME, "wb");
        int i = 1;
        while (freadSafe(&tempEmployee, S1) == 1) {
            if (answer == i) {
                // do nothing
            } else {
                fwriteSafe(&tempEmployee, TEMPS1);
            }
            i++;
        }
        fclose(S1);
        fclose(TEMPS1);
        remove(S1_NAME);
        rename(TEMPS1_NAME, S1_NAME);
        removeEmployee();
    }
}

int printEmployees(char searchLine[]) {
    system("cls");
    if ((S1 = fopen(S1_NAME, "rb")) == NULL) {
        printGeneralMenu("Файл не найден.");
        return 0;
    } else {
        struct employee tempEmployees[50];
        int tempRecordNumber = 0;
        struct employee empl;

        while (freadSafe(&empl, S1) == 1) {
            char birthyear[10];
            char salary[10];
            sprintf(birthyear, "%d", empl.birthyear);
            sprintf(salary, "%d", empl.salary);
            if (
                searchLine == "" ||
                strstr(empl.surname, searchLine) ||
                strstr(empl.name, searchLine) ||
                strstr(empl.patronymic, searchLine) ||
                strstr(empl.position, searchLine) ||
                strstr(birthyear, searchLine) ||
                strstr(salary, searchLine)
            ) {
                tempEmployees[tempRecordNumber] = empl;
                tempRecordNumber++;
            }
        }
        int i;
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
        fclose(S1);
        return tempRecordNumber;
    }

}

void exitProgram() {
    system("cls");
    printf("Вы действительно хотите выйти из программы? y/n: ");
    char answer = 'n';
    scanf("%s", &answer);
    if (answer == 'y') {
        // program exit
        exit(0);
    }
}

int freadSafe(struct employee *empl, FILE *S1) {
    int count;
    if ((count = fread(empl, EMPLOYEE_SIZE, 1, S1)) != 1) {
        if(ferror(S1)) {
            fclose(S1);
            printGeneralMenu("Ошибка чтения файла.");
        }
    }
    return count;
}

int fwriteSafe(struct employee *empl, FILE *S1) {
    int count;
    if ((count = fwrite(empl, EMPLOYEE_SIZE, 1, S1)) != 1) {
        if(ferror(S1)) {
            fclose(S1);
            printGeneralMenu("Ошибка записи файла.");
        }
    }
    return count;
}