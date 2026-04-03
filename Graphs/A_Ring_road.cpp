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

const int N = 500;
vector<pair<int,int>> g[N];
int vis[N];
int cost = 0;
void dfs(int u, int p = 0)
{
    vis[u] = 1;
    for(auto [v,w]: g[u])
    {
        if(!vis[v])
        {
            cost += w;
            dfs(v,u);
        }
        else if(v == 1 && p != 1)
        {
            cost += w;
        }
    }
}
void solve()
{
    // CODE HERE
    int n , u, v, w;
    cin >> n;
    int sum = 0;
    for(int i = 0; i<n; i++)
    {
        cin >> u >> v >> w;
        g[u].push_back({v,0});
        g[v].push_back({u,w});
        sum += w;
    }
    dfs(1);
    cout << min (cost, sum-cost) << '\n';
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