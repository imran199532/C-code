#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

float mulp(float n,int m)
{
    float ans=n*m;
    return ans;
}

int main()
{

    int m;
    float n;

    printf("Please...enter two number\n");
    scanf("%f",&n);
    scanf("%d",&m);

    float ans=mulp(n,m);

    printf("The ans is %f",ans);




}

