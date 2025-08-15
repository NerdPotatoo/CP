#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, k;
    cin >> n >> k;
    vector<ll> d;
    for(ll i = 1; i*i <= n; i++)
    {
        if(n%i == 0)
        {
            d.push_back(i);
            if(i != n/i) d.push_back(n/i);
        }
    }

    sort(d.begin(), d.end());

    if(k>d.size())
    {
        cout << -1 << '\n';
    }
    else{
        cout << d[k-1] << '\n';
    }
}