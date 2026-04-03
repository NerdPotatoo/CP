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
    int n, m;
    cin >> n >> m;
    DSU D(n);
    int extra = 0;
    while(m--)
    {
        int u, v;
        cin >> u >> v;
        if(D.same(u,v))
        {
            extra++;
        }
        else{
            D.merge(u,D.find(v));
        }
        vector<int> cnt(n+1);
        for(int i = 1; i<=n; i++)
        {
            cnt[D.find(i)]++;
        }
        vector<int> cc;
        for(int i = 0; i<cnt.size(); i++)
        {
            cc.push_back(cnt[i]);
        }

        sort(cc.rbegin(),cc.rend());

        int ans = cc[0];
        for(int i = 1; i<min((int)cc.size(), extra+1); i++)
        {
            ans += cc[i];
        }
        cout << ans - 1 << '\n';
    }
}