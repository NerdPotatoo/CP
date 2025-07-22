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
const int N = 1e5+10;
vector<int> g[N];
int vis[N];
const int mod = 1e9+7;
void dfs(int v)
{
    vis[v] = 1;
    for(int u:g[v])
    {
        if(!vis[u])
        {
            dfs(u);
        }
    }
}
void solve()
{
    // CODE HERE
    int n, m;
    cin >> n >> m;

    while(m--)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    int cnt = 0;
    vector<int> a;
    for(int i = 1; i<=n; i++)
    {
        if(!vis[i])
        {
            a.push_back(i);
            cnt++;
            dfs(i);
        }
    }

    cout << cnt - 1 << '\n';
    for(int i = 1; i<a.size(); i++)
    {
        cout << a[0] << ' ' << a[i] << '\n';
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