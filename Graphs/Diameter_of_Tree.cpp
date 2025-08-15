#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+9;

vector<int> g[N];
int depth[N];

void dfs(int u, int par = -1)
{
    for(auto v:g[u])
    {
        if(v==par) continue;
        depth[v] = depth[u] + 1;
        dfs(v,u);
        
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, u , v;
    cin >> n;

    for(int i = 1; i<n; i++)
    {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    
    dfs(1);
    int max_depth = -1;
    int max_d_node;
    for(int i = 1; i<=n; i++)
    {
        if(max_depth < depth[i])
        {
            max_depth = depth[i];
            max_d_node = i;
        }
        depth[i] = 0;
    }
    
    dfs(max_d_node);
    for(int i = 1; i<=n; i++)
    {
        if(max_depth < depth[i])
        {
            max_depth = depth[i];
        }
    }

    cout << max_depth << '\n';
}