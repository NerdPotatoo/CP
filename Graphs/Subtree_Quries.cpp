#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+9;
vector<int> g[N];
int subtree_sum[N];
int even_ct[N];

void dfs(int u, int p)
{
    if(u%2==0) {
        even_ct[u]++;
    }
    subtree_sum[u] = u;
    for(auto v:g[u])
    {
        if(v == p) continue;
        dfs(v,u);

        subtree_sum[u] += subtree_sum[v];
        even_ct[u] += even_ct[v];
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, u, v;
    cin >> n;
    for(int i = 1; i<=n; i++)
    {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,0);
    for(int i = 1; i<=n; i++)
    {
        cout << subtree_sum[i] << " " << even_ct[i] << '\n';
    }
}