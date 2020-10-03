#include<stdio.h>
#include<stdlib.h>
int main()
{
     int x;
     printf("ввидите номер месяца\n");
     scanf("%i",&x);
 
  switch (x)
  {
  	case 1: printf("пора года: зима\n");break;
  	case 2: printf("пора года: зима\n");break;
  	case 3: printf("пора года: весна\n");break;
  	case 4: printf("пора года: весна\n");break;
  	case 5: printf("пора года: весна\n");break;
  	case 6: printf("пора года: лето\n");break;
  	case 7: printf("пора года: лето\n");break;
  	case 8: printf("пора года: лето\n");break;
  	case 9: printf("пора года: осень\n");break;
  	case 10: printf("пора года: осень\n");break;
  	case 11: printf("пора года: осень\n");break;
  	case 12: printf("пора года: зима\n");break;
  	default: printf("такого месяца нет\n");
  }


}