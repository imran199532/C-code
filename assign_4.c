#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

int main()
{
    char s1[100];
    gets(s1);    //input string s1
     int len=strlen(s1);

     int i=0,j=len-1;

     int palin=1;       //first assume the string is a pallindrome

     while(i<j){                //checking is s1 is a palindrome
        if(s1[i]!=s1[j]){
            palin=0;
            break;
        }
        i++;
        j--;
     }

     if(palin==1){
        printf("'%s' is a pallinedrome",s1);
     }
     else printf("'%s' is not a pallinedrome",s1);

}

