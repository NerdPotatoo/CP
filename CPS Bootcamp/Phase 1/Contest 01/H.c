#include<stdio.h>
int main()
{
    int a, b;
    scanf("%d %d", &a,&b);
    int l = 1;
    for(int i = 1; i<=b; i++) l *= a;
    printf("%d\n", l);
    return 0;
}




