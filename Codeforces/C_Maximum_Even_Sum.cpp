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
int const N = 1e6+10;
vector<bool> prime(N+1, true);
vector<ll> p;


void solve()
{
    // CODE HERE
    ll a, b;
    cin >> a >> b;
    ll m = (a*b)/2 + 2;
    if(a&1 && b&1 )
    {
        cout << a*b + 1 << '\n';
    }
    
    else if(!(b&1))
    {
        
        if(!(m&1)) cout << m << '\n';
        else cout << -1 << '\n';
    }
    else{
        cout << -1 << '\n';
    }
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