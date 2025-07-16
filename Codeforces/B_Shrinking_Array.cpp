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
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &e:a) cin >> e;

    if(n==2)
    {
        if(abs(a[0]-a[1]) > 1) cout << -1 << '\n';
        else cout << 0 << '\n';

        return;
    }

    int ok = 2;

    for(int i = 2; i<n; i++)
    {
        if((abs(a[i-2]-a[i-1]) <= 1) || (abs(a[i-1]-a[i]) <= 1))
        {
            
            ok = min(0,ok);
        }

        if((min(a[i-2],a[i-1]) <= a[i] && max(a[i-2],a[i-1]) >= a[i]) || (min(a[i-1],a[i]) <= a[i-2] && max(a[i-1],a[i]) >= a[i-2]))
        {
            ok = min(1,ok);
        }
    }

    if(ok == 2) cout << -1 << '\n';
    else cout << ok << '\n';
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