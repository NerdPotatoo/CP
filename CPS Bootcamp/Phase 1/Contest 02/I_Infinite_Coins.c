#include<stdio.h>

int main()
{
    int a, b;
    scanf("%d %d", &a,&b);
    if(b >= a%500)
    {
        printf("Yes\n");
    }
    else printf("No\n");
}