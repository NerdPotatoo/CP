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
        int n;
        cin >> n;
        int cnt = 0;
        for(int i = 1; i*i <=n; i++)
        {
            if(n%i==0)
            {
                cnt++;
                if(i!= n/i) cnt++;
            }
        }
        cout << cnt << '\n';
    }
}