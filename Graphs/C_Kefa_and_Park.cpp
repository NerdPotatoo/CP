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

const int N = 1e5+5;
vector<int> g[N];
int vis[N];
int mark[N];
int ans = 0, k;

void dfs(int v, int m)
{
    // yes
    vis[v] = 1;
    if(mark[v]) m++;
    else m = 0;
    if(m>k) return;
    if(g[v].size() == 1 && vis[g[v][0]])
    {
        ans++;
    }
    for(int u : g[v])
    {
        if(!vis[u])
        {
            dfs(u,m);
        }
    }
}
void solve()
{
    // CODE HERE
    int n;
    cin >> n >> k;
    for(int i = 1; i<=n; i++)
    {
        int x;
        cin>> x;
        mark[i] = x; 
    }
    int edge = n-1;
    while(edge--)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    // yes
    dfs(1, 0);
    cout << ans << '\n';
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