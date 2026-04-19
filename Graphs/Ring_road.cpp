#include<bits/stdc++.h>
#define ll long long
using namespace std;
int cost;
const int N  = 105;
vector<pair<int,int>> g[N];
bool vis[N];
void dfs(int u, int p = 0)
{
    vis[u] = true;
    for(auto [v,c]:g[u])
    {
        if(!vis[v])
        {
            cost += c;
            dfs(v,u);
        }
        else if(v == 1 && p != 1)
        {
            cost += c;
        }
    }
}
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    int sum = 0;
    for(int i = 1; i<=n; i++)
    {
        int u, v, c; cin >> u >> v >> c;
        g[u].push_back({v,0});
        g[v].push_back({u,c});
        sum += c;
    }

    cost = 0;
    dfs(1);

    cout << min(cost, sum-cost) << '\n';
}    