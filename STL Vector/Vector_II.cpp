#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q;cin >> n >> q;
    vector<vector<ll>> v(n);
    ll val;
    while(q--)
    {
        int t, x;
        cin >> x >> t;
        if(x == 0)
        {
            cin >> val;
            v[t].push_back(val);
        }
        else if( x == 1 )
        {
            int len = v[t].size();
            for(int i = 0; i<len; i++)
            {
                if(i < len -1)cout << v[t][i] << ' ';
                else cout << v[t][i];

            }
            // if(v[t].size()) cout << v[t][v[t].size()-1];
            cout << endl;
        }
        else{
            v[t].clear();
        }
    }
}