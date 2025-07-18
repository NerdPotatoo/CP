#include<stdio.h>
int main()
{
    long long int a, b, ans;
    scanf("%lld %lld", &a, &b);
    if(a%b)
    {
        ans = a/b;
        ans++;
    }
    else ans = a/b;
    printf("%lld", ans);
}