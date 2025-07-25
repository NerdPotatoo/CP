#include<stdio.h>

int main()
{
    int t; scanf("%d",&t);
    while(t--)
    {
        int n,x = 0,  res = 0; scanf("%d", &n);
        for(int i = 1; i<=n; i++)
        {
            int a,b;
            scanf("%d%d", &a,&b);
            if(a<=10 && x<b)
            {
                x = b;
                res = i;
            }
        }
        printf("%d\n", res);
    }
}