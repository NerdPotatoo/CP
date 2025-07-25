#include<stdio.h>

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int k;
        scanf("%d",&k);
        int cnt = 1;
       for(int i = 1; ; i++)
       {
            if(i%3==0 || i%10 == 3) continue;
            if(cnt == k)
            {
                printf("%d\n", i);
                break;
            }
            cnt++;
       }
       

    }
}