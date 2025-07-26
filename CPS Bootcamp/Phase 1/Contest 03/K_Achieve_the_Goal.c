#include<stdio.h>

void solve()
{
    // CODE HERE
    int n,k,m, s = 0, a;
    scanf("%d %d %d", &n , &k , &m);
    for(int i = 1; i<n; i++)
    {
        scanf("%d", &a);
        s += a;
    }

    int rem = (n*m) - s;
    // printf("rem: %d ", rem);
    if(rem > k)
    {
        printf("-1\n");
    }
    else{
        if(rem <= 0)
        {
            printf("0\n");
        }
        else{
            printf("%d\n", rem);
        }
    }

}
int main()
{
    int T = 1;
    // scanf("%d", &T);
    for(int cs = 1; cs <= T; cs++)
    {
        // printf("Case %d: ", cs);
        solve();
    }
    return 0;
}