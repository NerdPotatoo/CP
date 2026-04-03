#include<bits/stdc++.h>
using namespace std;
const int maxN = 1e5+7;
int par[maxN], rnk[maxN];
int _find(int a)
{
    return par[a] = (par[a] == a ? a:_find(par[a]));
}
void _union(int u , int v)
{
    u = _find(u);
    v = _find(v);
    if(rnk[u] == rnk[v])
    {
        rnk[u]++;
    }
    if(rnk[u]>rnk[v]) par[v] = u;
    else par[u] = v;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    for(int i = 0; i<maxN; i++) par[i] = i;
    int n, m;
    cin >> n >> m;
    for(int i = 1; i<=m; i++)
    {
        int u, v;
        cin >> u >> v;
        _union(u,v);
    }
    int d; cin >> d;
    set<int> s;
    for(int i = 1; i <= d; i++)
    {
        int u, v;
        cin >> u >> v;
        if(_find(u) == _find(v)) 
            s.insert(_find(u));
    }

    vector<int> cnt(n+1, 0);
    for(int i = 1; i <= n; i++)
    {
        int p = _find(i);
        if(s.find(p) == s.end())
        {
            cnt[_find(i)]++;
        }
    }
    int ans = INT_MIN;
    for(int i = 1; i<=n; i++)
    {
        ans = max(ans, cnt[_find(i)]);
    }
    cout << ans << '\n';
}