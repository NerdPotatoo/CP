#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while(t--)
    {
        int n, x;
        cin >> n;
        vector<int> a(n+1);
        for(int i = 1; i<=n; i++)
        {
            cin >> x;
            a[x]++;
        }
        int ans = -1;
        for(int i = 1; i<=n; i++)
        {
            if(a[i] >= 3)
            {
                ans = i;
                break;
            }
        }
        cout << ans << '\n';
    }
}