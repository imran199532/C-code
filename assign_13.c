#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

int main()
{
    char s1[100],s2[100];
    int n,m,i;
    gets(s1);    //input string s1
    scanf("%d",&n);     //take the position from where we should start coping
    scanf("%d",&m);         //take number of characters to cut;

    for( i=n;i<n+m;i++){            //coping portion of s1 to s2
        s2[i-n]=s1[i];
    }
    puts(s2);

}
