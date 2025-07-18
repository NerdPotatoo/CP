#include<stdio.h>
int main()
{
    int a, b, area, parameter;
    scanf("%d %d", &a, &b);
    area = a*b;
    parameter = 2*(a+b);
    printf("%d %d\n", area, parameter);
}