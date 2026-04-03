#include<bits/stdc++.h>
using namespace std;
struct DSU{
    vector<int> par,rnk,siz;
    int c;
    DSU(int n) : par(n+1, -1), rnk(n+1, 0), siz(n+1, 1), c(n) {
        for(int i = 1; i<=n; i++)
        {
            par[i] = i;
        }
    }
    int find(int u)
    {
        return (par[u] == u ? u : ( par[u] = find(par[u]) ));
    }
    bool same(int u , int v)
    {
        return (find(u) == find(v));
    }
    int getSize(int u)
    {
        return siz[find(u)];
    }
    int cnt()
    {
        return c;
    }
    void merge(int u, int v)
    {
        if((u = find(u)) == (v = find(v)))
        {
            return;
        }
        else{
            c--;
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
        siz[v] += siz[u];
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, k;
    cin >> n >> m >> k;
    for(int i = 1; i<=m; i++)
    {
        int u, v;
        cin >> u >> v;
    }

    DSU D(n);
    vector<string> ans;
    vector<tuple<string, int, int>> a;
    for(int i = 1; i<=k; i++)
    {
        string q; int u, v;
        cin >> q >> u >> v;
        a.push_back({q,u,v});
    }
    reverse(a.begin(),a.end());
    for(auto [q,u,v] : a)
    {
        if(q == "cut")
        {   
            D.merge(u,v);
        }
        else{
            ans.push_back((D.same(u,v)) ? "YES" : "NO");
        }
    }
    reverse(ans.begin(),ans.end());
    for(string val:ans)
    {
    cout << val << '\n';        
    }
}