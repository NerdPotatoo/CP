#include<stdio.h>

int main()
{
    char a,b,c;
    scanf("%c%c%c", &a,&b,&c);

    int f = (int)a-48;
    int s = (int)b-48;
    int t = (int)c-48;

    int a1 = f*100+s*10+t;
    int a2 = s*100+t*10+f;
    int a3 = t*100+f*10+s;

    printf("%d\n", a1+a2+a3);
}