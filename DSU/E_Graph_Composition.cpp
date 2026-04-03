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
    int t;
    cin >> t;
    while(t--)
    {
        int n, m1,m2;
        cin >>n >> m1 >> m2;
        DSU f(n), g(n);
        vector<pair<int,int>> ed1, ed2;
        for(int i = 0; i<m1; i++)
        {
            int u,v;
            cin >> u >> v;
            ed1.push_back({u,v});
        }
        for(int i = 0; i<m2; i++)
        {
            int u,v;
            cin >> u >> v;
            ed2.push_back({u,v});
            g.merge(u,v);
        }
        int ans = 0;
        for(int i = 0; i<m1; i++)
        {
            if(g.same(ed1[i].first,ed1[i].second))
            {
                f.merge(ed1[i].first,ed1[i].second);
            }
            else{
                ans++;
            }
        }

        ans += abs(f.cnt() - g.cnt());
        cout << ans << '\n';
    }
}