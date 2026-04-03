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
const int N = 120;
vector<pair<int,int>> g[N];
int depth[N];
void dfs(pair<int,int>  u, int par = -1)
{
    int node = u.first;
    int w = u.second;
    for( auto v : g[node])
    {
        if(v.first == par) continue;
        depth[v.first] = depth[u.first] + v.second;
        dfs(v,node);
    }
}
void solve()
{
    // CODE HERE
    int n, u,v, w;
    cin >> n;
    for(int i = 1; i<n; i++)
    {
        cin >> u >> v >> w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    int ans = 0;
    for(auto u:g[0])
    {
        depth[u.first] = u.second;
        dfs(u,0);
    }
    for(int i = 0; i<n; i++)
    {
        ans = max(ans, depth[i]);
    }
    cout  << ans << '\n';
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