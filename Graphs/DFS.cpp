#include<bits/stdc++.h>
using namespace std;
const int N = 1e3;
vector<int> g[N];
int vis[N]; 

void dfs(int ver)
{
    // Take action on vertex after entering the vertex
    vis[ver] = 1;
    cout << ver << ' ';
    for(int child : g[ver])
    {
        if(vis[child]) continue;
        // Take action on child before entering the child node
        dfs(child);
        // Take action on child after exiting the child node
    }
    // Take action on vertex before exiting the vertex
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >>n >> m;
    while(m--)
    {
        int u, v;
        cin >> u >> v;

        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1);
    
}

// Time Complexity: O(V+E)