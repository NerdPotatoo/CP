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
    while(m--)
    {
        int k;
        cin >> k;
        vector<int> v(k);
        for(int i = 0; i<k ; i++)
        {
            cin >> v[i];
            
        }
        for(int i = 0; i<k-1; i++)
        {
            D.merge(v[i],v[i+1]);
        }
    }
    for(int i = 1; i<=n; i++)
    {
        cout << D.getSize(i) << ' ';
    }
    cout << endl;
}