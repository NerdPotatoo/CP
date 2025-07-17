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
    int mat[n+1][n+1];
    int u, v, x;

    for(int i = 1; i<=n; i++)
    {
        for(int j = 1; j<=n; j++)
        {
            mat[i][j] = 0;
        }
    }
    for(int i = 1; i<=n; i++)
    {
        cin >> u >> v;
        while(v--)
        {
            cin >> x;
            mat[u][x] = 1;
        }
    }


    for(int i = 1; i<=n; i++)
    {
        for(int j = 1; j<n; j++)
        {
            cout << mat[i][j] << ' ';
        }
        cout << mat[i][n] <<'\n';
    }
}
int32_t main()
{
    fastIO;
    int T = 1;
    // cin>>T;
    for(int cs = 1; cs <= T; cs++)
    {
        // cout<<"Case "<<cs<< ": "<<solve();
        solve();
    }
    return 0;
}