#include<stdio.h>
#include<math.h>
int main()
{
    int a, b;
    scanf("%d %d", &a,&b);
    int l = 1, r = 1;
    for(int i = 1; i<=b; i++) l *= a;
    for(int i = 1; i<=a; i++) r *= b;
    printf("%d\n", l+r);
    return 0;
}




