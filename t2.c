#include<stdio.h>

int is_equal(int *arr1,int *arr2)
{
    int i;
    int n=sizeof(arr1)/4;   //finding length of the array
    int m=sizeof(arr2)/4;

    if(n!=m)return 0;   //if array size is not equal, the arrays are surely not identical
    for(i=0;i<n;i++){
        if(arr1[i]!=arr2[i])return 0;
    }

    return 1;   //as every element is equal,the arrays are identical


}

int main()
{
    int n,m,i;            //n is size of first array, y is size of second array
    printf("enter size of two arrays\n");
    scanf("%d %d",&n,&m);

    int arr1[n],arr2[m];

    printf("enter all elements of the first array\n");
    for(i=0;i<n;i++)scanf("%d",&arr1[i]);
    printf("enter all elements of the second array\n");
    for(i=0;i<m;i++)scanf("%d",&arr2[i]);

    int ans=is_equal(arr1,arr2);
    if(ans==1){
        printf("the arrays are identical");
    }
    else printf("the arrays are not identical");

}

