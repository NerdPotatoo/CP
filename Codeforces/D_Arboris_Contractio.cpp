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
const int N = 2e5+9;
vector<int> g[N];
int vis[N];
int leaf[N];
int leafCnt = 0;
void dfs(int u, int p)
{   
    vis[u] = 1;
    if(g[u].size() == 1 && (g[u][0] == p || p == 0) ){
        leafCnt++;
        leaf[u] = 1;
    }
    for(auto v:g[u])
    {
        if(!vis[v]) dfs(v,u);
    }
}
void solve()
{
    // CODE HERE
    int n, u, v;
    cin >> n;
    for(int i = 0; i<=n; i++)
    {
        g[i].clear();
        vis[i] = 0;
        leaf[i] = 0;
    }
    
    for(int i = 1; i<n; i++)
    {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    leafCnt = 0;
    dfs(1,0);
    if(n == 2) {
        cout << 0 << '\n';
        return;
    }
    int ans = INT_MAX;
    for(int i = 1; i<=n; i++)
    {
        int cnt = 0;
        for(auto x:g[i])
        {
            if(leaf[x]) cnt++;
        }
        ans = min(ans, leafCnt - cnt);
    }
    cout << ans << '\n';
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