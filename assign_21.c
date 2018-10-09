#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

int main()
{
    char s1[100];
    int n,m,i;
    gets(s1);    //input string s1
    int len=strlen(s1);

    int dif='a'-'A';

    for(i=0;i<len;i++){
        if(i==0){
            if(s1[i]>='a' && s1[i]<='z')s1[i]=s1[i]-dif;       //first character of the sentence will always be capital
            continue;
        }                                                   //s1[i]=s1[i]-dif ---convert lowercase to upper case

        if(s1[i-1]==' '){       //if i is the start of a word
            if(s1[i]>='a' && s1[i]<='z')s1[i]=s1[i]-dif;
        }


    }

    puts(s1);


}

