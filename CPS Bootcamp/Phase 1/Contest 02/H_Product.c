#include<stdio.h>

int main()
{
    int a, b ;
    scanf("%d%d",&a,&b);
    int ans = a*b;
    if(ans&1) 
    {
        printf("Odd\n");
    }
    else{
        printf("Even\n");
    }
}