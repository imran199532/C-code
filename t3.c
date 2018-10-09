#include<stdio.h>

struct date      //the date structure
{
    int day;
    char month[15];        //as month is represented as string in the output
    int year;               //month is taken as a string
};

int main()
{
    struct date *var;          //declaring pointer variable of type date
    struct date var1={15,"may",2018};     //declearing another variable ,setting the values
    var=&var1;                            //assiging values of var1 to var


    printf("%s %d, %d",var->month,var->day,var->year);
}
