#include<bits/stdc++.h>
using namespace std;
struct DSU{
    vector<int> par,rnk,siz;
    int c;
    DSU(int n) : par(n+1, 0), rnk(n+1, 0), siz(n+1, 1), c(n) {
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
    DSU D1(n), D2(n);
    int u,v;
    for(int i = 1; i<=m; i++)
    {
        cin >> u >> v;
        D1.merge(u,v);
    }
    for(int i = 1; i<=k; i++)
    {
        cin >> u >> v;
        D2.merge(u,v);
    }

    vector<pair<int,int>> ans;
    for(int i = 1; i<=n; i++)
    {
        for(int j = i+1; j<=n; j++)
        {
            if(i!=j)
            {
                if(!D1.same(i,j) && !D2.same(i,j))
                {
                    D1.merge(i,j);
                    D2.merge(i,j);
                    ans.push_back({i,j});
                }
            }
        }
    }

    cout << ans.size() << '\n';
    for(auto [x,y]:ans)
    {
        cout << x << " " << y << '\n';
    }
}