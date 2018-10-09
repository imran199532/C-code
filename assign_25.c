#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
int add(int n,int m)
{
    return n+m;
}

int sub(int n,int m)
{
    return n-m;
}

int mulp(int n,int m)
{
    return n*m;
}

int division(int n,int m)
{
    return n*1.0/m;
}

int mod(int n,int m)
{
    return n%m;
}



int main()
{

    int n,m,i;


    printf("Please enter two numbers\n\n");
    scanf("%d",&n);
     scanf("%d",&m);

    printf("Enter your choice from below\n");

    printf("a. addition\n");
    printf("b. subtraction\n");
    printf("c. multiplication\n");
    printf("d. division\n");
    printf("e. modulus\n\n");

    char ch;
    while(1){

        scanf("%c",&ch);            //input choice
        if(ch<='e' && ch>='a')break;
    }


    int ans=0;

    if(ch=='a'){
        ans=add(n,m);
    }

    else if(ch=='b'){
        ans=sub(n,m);
    }
    else if(ch=='c'){
        ans=mulp(n,m);
    }
    else if(ch=='d'){
        ans=division(n,m);
    }
    else{
        ans=mod(n,m);
    }

    printf("The ans is %d",ans);


}

