#include<stdio.h>

int main()
{
    int t;
    scanf("%d",&t);

    while(t--)
    {
        int n;
        scanf("%d",&n);
        int count = 0, m = n;
        
        for(int i = 1; i<= 10000; i*=10)
        {
            int rem = m%10;
            m/=10;
            if(rem*i) count++;
        }
        printf("%d\n", count);
        for(int i = 1; i<= 10000; i*=10)
        {
            int rem = n%10;
            n/=10;
            if(rem*i) printf("%d ", rem*i);
        }
        printf("\n");
    }
}