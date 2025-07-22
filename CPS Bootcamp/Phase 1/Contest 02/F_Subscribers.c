#include<stdio.h>

int main()
{
    long long int n;
    scanf("%lld", &n);

    if(n<1e3)
    {
        // n
        printf("%lld", n);
    }
    else if (n >= 1e3 && n<(1e4)){
        // - mod 10
        printf("%lld",(n/10)*10);
    }
    else if (n >= 1e4 && n<(1e5))
    {
        // - mod 100 
        printf("%lld", (n/100)*100);
    }
    else if (n >= 1e5 && n<(1e6))
    {   
        // - mod 1000
        printf("%lld", (n/1000)*1000);
    }
    else if (n >= 1e6 && n<(1e7))
    {
        // - mod 10000
        printf("%lld", (n/10000)*10000);
    }
    else if (n >= 1e7 && n<(1e8))
    {
        // - mod 100000
        printf("%lld", (n/100000)*100000);
    }
    else if (n >= 1e8 && n<(1e9))
    {
        // - mod 1000000
        printf("%lld", (n/1000000)*1000000);
    }
    printf("\n");
}