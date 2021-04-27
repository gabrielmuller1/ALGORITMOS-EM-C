#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

typedef struct peopleBirthdate{
    int day;
    int month;
    int year;
}PEOPLEBIRTHDATE;

void calculeAge(PEOPLEBIRTHDATE data);

void calculeAge(PEOPLEBIRTHDATE data){
    struct tm *localData;
    time_t seconds;

    time(&seconds);
    localData = localtime(&seconds);

    int daysDiff, monthDiff, yearDiff;

    if(localData->tm_mon + 1 > data.month){
        monthDiff = abs(localData->tm_mon + 1 - data.month);
        daysDiff = abs(localData->tm_mday);

        if (daysDiff > 0 && monthDiff > 0){
            yearDiff = abs(localData->tm_year + 1900 - data.year);
        }
        
    }else{
        daysDiff = 30 - abs(localData->tm_mday - data.day);
        monthDiff = 11 - abs(localData->tm_mon + 1 - data.month);
        yearDiff = abs(localData->tm_year + 1900 - data.year) - 1;
    }

    printf("%i anos, %i mes(es) e %i dias", yearDiff, monthDiff, daysDiff);
}

int main(void){
    PEOPLEBIRTHDATE people;

    printf("Informe o ano do seu nascimento: ");
    scanf("%i", &people.year);
    fflush(stdin);

    printf("Informe o mes do seu nascimento: ");
    scanf("%i", &people.month);
    fflush(stdin);

    printf("Informe o dia do seu nascimento: ");
    scanf("%i", &people.day);
    fflush(stdin);

    printf("\nIdade: ");
    calculeAge(people);
}
