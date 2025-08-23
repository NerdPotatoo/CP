#include<bits/stdc++.h>
using namespace std;
#define ll long long
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
        vector<ll> a(n),b;
        for(auto &e:a) {
            cin >> e;
            b.push_back(e);
        }
        sort(b.rbegin(), b.rend());
        ll mx = b[0];
        ll mx2 = b[1];
        for(auto x : a)
        {
            if(x != mx)
            {
                cout <<  x - mx << ' ';
            }
            else{
                cout << x - mx2 << ' ';
            }
        }
        cout << '\n';
    }
}