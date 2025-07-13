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
    int a,b,x,y;
    cin >> a >> b >> x >> y;
    if(a>b)
    {
        if(b+1 == a && (a^1) == b)
        {
            cout << y << '\n';
            return;
        }
        cout << -1 << '\n';
    }
    else{
        int op = b-a, res;

        if(!(a&1))
        {
            res = ((op+1)/2)*min(x,y) + (op/2)*x;
        }
        else{
            res = (op/2)*min(x,y) + ((op+1)/2)*x;
        }
        cout << res << '\n';
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