#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

#define ll long long
#define endl '\n'
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
#define fastIO ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
template <typename T> using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;


const int N = 1e5+10;

void dfs(int u, int cost, vector<pair<int,int>> g[], int &res)
{
    if(g[u].size() == 0)
    {
        res = min(res,cost);
        return;
    }

    for(auto [v,c]:g[u])
    {
        dfs(v,c+cost, g, res);
    }
}
void solve()
{
    // CODE HERE
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<pair<int,int>> g[n+1];
    int res = INT_MAX;
    for(int i = 1; i<=n; i++)
    {
        int u,v;
        cin >> u >> v;

        if(s[i-1] == 'U')
        {
           if(u) g[i].push_back({u,1});
           if(v) g[i].push_back({v,1});
        }
        else if(s[i-1] == 'L')
        {
           if(u) g[i].push_back({u,0});
           if(v) g[i].push_back({v,1});
        }
        else{
           if(u) g[i].push_back({u,1});
           if(v) g[i].push_back({v,0});
        }
    }
    dfs(1,0, g, res);
    cout << res << '\n';
}
int32_t main()
{
    fastIO;
    int T = 1;
    cin>>T;
    for(int cs = 1; cs <= T; cs++)
    {
        // cout<<"Case "<<cs<< ": "<<solve();
        solve();
    }
    return 0;
}