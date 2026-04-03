#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define fastIO ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);


const int N = 2e5+10;
vector<int> g[N];
vector<set<int>> path(N);
void fun(int u, int v)
{
    for(auto x : path[v])
    {
        path[u].insert(x);
    }
}
void dfs(int u)
{
    for(auto v : g[u])
    {
        dfs(v);    
        fun(u,v);
        path[u].insert(v);
    }
}
void solve()
{
    // CODE HERE
    int n, m;
    cin >> n >> m;
    int u, v;
    for(int i = 0; i<m; i++)
    {
        cin >> u >> v;
        g[u].push_back(v);
    }
    dfs(1);
    for(int i = 1; i<=n; i++)
    {
        cout << i << ": ";
        for(auto x : path[i])
        {
            cout << x << " ";
        }
        cout << endl;
    }
    int q;
    cin >> q;
    while(q--)
    {
        cin >> u >> v;
        if(path[u].find(v)!=path[u].end()) cout << 0 <<'\n';
        else cout << abs(u-v) << '\n';
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