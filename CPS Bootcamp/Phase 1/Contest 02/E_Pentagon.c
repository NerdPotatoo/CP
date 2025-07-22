#include<stdio.h>
#include<math.h>
int main()
{
    char p,q,r,s;
    scanf("%c%c\n%c%c", &p, &q, &r, &s);
    // printf("%c %c %c %c", p, q , r ,s );
    int x, y;
    if(abs(p-q) == 1 || abs(p-q) == 4) x = 1;
    else x = 2;
    if(abs(r-s) == 1 || abs(r-s) == 4) y = 1;
    else y = 2;

    if(x == y)
    printf("Yes\n");
    else
    printf("No\n");
}   