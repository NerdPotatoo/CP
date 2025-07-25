#include<stdio.h>

int main()
{
    int n,x, sum = 0, a;
    scanf("%d %d", &n, &x);
    for(int i = 1; i<=n; i++)
    {
        scanf("%d", &a);
        if(a<=x) sum += a;
    }
    printf("%d\n", sum);
}