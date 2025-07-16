#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

#define ll long long
#define endl '\n'
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define fastIO ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
template <typename T> using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;


const int mod = 1e9+7;

void solve()
{
    // CODE HERE
    ll n, mx = -1, mn = INT_MAX;
    cin >> n;
    vector<ll> a(n), d, f(n);
    for(auto &e:a) {
        cin >> e;
        mn = min(e,mn);
        mx = max(e,mx);
    }
    //sort(all(a));
    ll res = mx-mn;
    f[0] = a[0];
    for(int i = 1; i<n; i++)
    {
        f[i] = f[i-1]+a[i];
    }

    for(int i = 2; i*i <= n; i++)
    {
        if(n%i == 0)
        {
            d.push_back(i);
            if(i!=(n/i)) d.push_back(n/i);
        }
    }

    // for(auto x:f) cout << x << " ";
    // cout << endl;
    // for(auto x:d) cout << x << " ";
    // cout << endl;
    // cout << mx - mn << " ";
    for(int i = 0; i<d.size(); i++)
    {
        ll k = d[i];
        mn = f[k-1],mx = f[k-1];
       for(ll j = k-1; j<n; j+=k)
       {
            if(j==k-1)
            {
                mx = max(mx,f[j]);
                mn = min(mn,f[j]);
            }
            else{
                mx = max(mx,f[j]-f[j-k]);
                mn = min(mn,f[j]-f[j-k]);
            } 
       }
    //    cout << k << " -> " << mx << " " << mn << " " << mx-mn<<'\n';
       res = max(res, mx-mn);
    }
    cout << res << '\n';
    // cout << a[n-1]-a[0] ;
}
int32_t main()
{
    fastIO;
    int T = 1;
    cin>>T;
    for(int cs = 1; cs <= T; cs++)
    {
        // cout<<"Case "<<cs<< ": "<<solve();
        solve();
    }
    return 0;
}