#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5+6;
vector<int> g[N];
bool vis[N];

void dfs(int u)
{
    vis[u] = true;
    for(auto v:g[u])
    {
        if(!vis[v]) dfs(v);
    }
}
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    while(m--)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> nodes;
    for(int i = 1; i<=n; i++)
    {
        if(!vis[i]){
            nodes.push_back(i);
            dfs(i);
            
        } 
    }
    cout << nodes.size() - 1 << '\n';
    for(int i = 1; i<nodes.size(); i++)
    {
        cout << nodes[i-1] << ' ' << nodes[i] << endl;
    }

}    