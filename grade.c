#include<stdio.h>
int main()
{
    int mark;
    scanf("%d",&mark);

    switch(mark>=90){
        case 1:
            printf("Grade A");
            return;

        default:
            break;


    }

    switch(mark>=70){
        case 1:
            printf("Grade B");
            return;

        default:
            break;


    }
    switch(mark>=60){
        case 1:
            printf("Grade C");
            return;

        default:
            break;


    }
    switch(mark>=40){
        case 1:
            printf("Grade D");
            return;

        default:
            printf("Grade F");
            break;


    }
}
