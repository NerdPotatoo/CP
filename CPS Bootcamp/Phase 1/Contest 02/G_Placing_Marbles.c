#include<stdio.h>

int main()
{
    char a, b , c;
    scanf("%c%c%c",&a,&b,&c);
    int ans = a-'0' + b-'0' + c - '0';
    printf("%d\n", ans);
}