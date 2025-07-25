#include<stdio.h>

void solve()
{
    // CODE HERE
    int n, k;
    scanf("%d %d", &n, &k);

    int x = n - (k-1);
    int y = n - 2*(k-1);

    if(x>=1 && x&1)
    {
        printf("YES\n");
        for(int i = 1; i<k; i++)
        {
            printf("1 ");
        }
        printf("%d\n", x);
    }
    else if(y>=1 && !(y&1))
    {
        printf("YES\n");
        for(int i = 1; i<k; i++)
        {
            printf("2 ");
        }
        printf("%d\n", y);
    }
    else{
        printf("NO\n");
    }
}
int main()
{
    int T = 1;
    scanf("%d", &T);
    for(int cs = 1; cs <= T; cs++)
    {
        // printf("Case %d: ", cs);
        solve();
    }
    return 0;
}