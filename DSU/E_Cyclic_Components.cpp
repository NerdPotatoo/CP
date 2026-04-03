#include<bits/stdc++.h>
using namespace std;
struct DSU{
    vector<int> par,rnk;
    DSU(int n) : par(n+1, 0), rnk(n+1, 0) {
        for(int i = 1; i<=n; i++)
        {
            par[i] = i;
        }
    }
    int find(int u)
    {
        return (par[u] == u ? u : ( par[u] = find(par[u]) ));
    }
    void merge(int u, int v)
    {
        if((u = find(u)) == (v = find(v)))
        {
            return;
        }
        if(rnk[u] > rnk[v])
        { 
            swap(u,v);
        }
        else if(rnk[u] == rnk[v])
        {
            rnk[v]++;
        }
        par[u] = par[v];
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    vector<int> g[n+1];
    DSU D(n);
    for(int i = 1; i<=m; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v); 
        g[v].push_back(u); 
        D.merge(u,v);
        
    }
    vector<vector<int>> cnt(n+1);
    for(int i = 1; i<=n; i++)
    {
        cnt[D.find(i)].push_back(i);
    }
    int ans = 0;
    for(int i = 1; i <= n; i++)
    {
        
        if(cnt[i].size() >= 3)
        {
            int ok = 1;
            for(int u : cnt[i])
            {
                if(g[u].size() != 2)
                {
                    ok = 0;
                    break;
                }
            }
            if(ok) ans++;
        }
        
    }

    cout << ans << '\n';

    
    
}