#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

float average(int n,int m,int p)
{
    float ans=(n+m+p)/3.0;
    return ans;
}

int main()
{
    int n,m,p;

    printf("Please enter marks of 3 subjects\n");
    scanf("%d %d %d",&n,&m,&p);

    float ans=average(n,m,p);

    printf("The ans is %f",ans);

}

