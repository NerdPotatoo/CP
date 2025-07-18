#include<stdio.h>
int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    int d = a/b;
    int r = a%b;
    double f = a*1.0/b;
    printf("%d %d %.5lf", d,r,f);
    return 0;
}