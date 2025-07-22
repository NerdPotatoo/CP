#include<stdio.h>

int main()
{
    int x,  y;
    scanf("%d %d", &x, &y);
    int up = y-x, dwn = x-y;

    if((up<=2 && up>0) || (dwn <= 3 && dwn>0)) printf("Yes\n");
    else printf("No\n"); 
}