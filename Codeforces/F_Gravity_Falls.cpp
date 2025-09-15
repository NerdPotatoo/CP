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

void solve()
{
    // CODE HERE
    int n, k;
    cin >> n;
    vector<vector<int>> v(n);
    for(auto &v1:v)
    {
        cin >> k;
        v1.resize(k);
        for(auto &e:v1) cin >> e;
    }
    sort(all(v));
    vector<int> ans;

    while(!v.empty())
    {
        for(int x : v[0])
        {
            ans.push_back(x);
        }
        int t = v[0].size();
        vector<vector<int>> tmp;

        for(int i = 1; i<v.size(); i++)
        {
            if(v[i].size() > t)
            {
                vector<int> p;
                for(int j = t; j<v[i].size(); j++)
                {
                    p.push_back(v[i][j]);
                }
                tmp.push_back(p);
            } 
        }

        v = tmp;
        sort(all(v));
    }
    for(int x:ans)
    {
        cout << x << ' ';
    }
    cout << endl;
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