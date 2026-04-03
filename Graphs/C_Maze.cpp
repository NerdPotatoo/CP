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


const int mod = 1e9+7;
int n, m, k, si, sj;
char g[510][510];
int vis[510][510];
bool valid(int i , int j)
{
    return (i>=0 && i<n && j>=0 && j<m);
}
vector<pair<int,int>> d = {{0,1},{1,0},{-1,0},{0,-1}};
void dfs(int i,int j)
{
    
    vis[i][j] = 1;
    for(int l = 0; l<4; l++)
    {
        int ci = i + d[l].first; 
        int cj = j + d[l].second; 
        if(valid(ci,cj) && !vis[ci][cj])
        {
            dfs(ci,cj);
        }
    }
    if(k>0)
    {
        g[i][j] = 'X';
        --k;
    }
}
void solve()
{
    // CODE HERE
    cin >> n >> m >> k;
    bool ok = true;
    
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<m; j++)
        {
            cin >> g[i][j];
            if(ok)
            {
                if(g[i][j] == '.') si = i, sj = j, ok = false;
            }
            vis[i][j] = (g[i][j] == '#')? 1:0; 
        }
    }
    dfs(si,sj);
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<m; j++)
        {
            cout << g[i][j];
        }
        cout << '\n';
    }
}
int32_t main()
{
    fastIO;
    int T = 1;
    // cin>>T;
    for(int cs = 1; cs <= T; cs++)
    {
        // cout<<"Case "<<cs<< ": "<<solve();
        solve();
    }
    return 0;
}