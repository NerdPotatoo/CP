#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, q, val;
    cin >> n >> q;
    multiset<ll> ml;
    for(int i = 0; i < n; i++)
    {
        cin >> val;
        ml.insert(val);
    }
    while(q--)
    {
        cin >> val;
        auto it = ml.upper_bound(val);

        if(it == ml.begin())
        {
            cout << -1 << endl;
        }
        else 
        {
            it--;
            cout << *it << '\n';
            ml.erase(it);
        }
        
    }
}