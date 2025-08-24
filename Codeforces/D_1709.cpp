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
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(auto &e:a) cin >> e;
    for(auto &e:b) cin >> e;
    vector<pair<int,int>> ans;
    
    for(int i = 0; i<n; i++)
    {
        for(int j = 1; j<n; j++)
        {
            if(a[j-1]>a[j])
            {
                swap(a[j-1],a[j]);
                ans.push_back({1,j});
            }
        }
    }

    for(int i = 0; i<n; i++)
    {
        for(int j = 1 ; j<n; j++)
        {
            if(b[j-1] > b[j])
            {
                swap(b[j-1],b[j]);
                ans.push_back({2,j});
            }
        }
    }
    for(int i = 0;i<n; i++)
    {
        if(a[i]>b[i])
        {
            swap(a[i],b[i]);
            ans.push_back({3,i+1});
        }
    }
    cout << ans.size() << '\n';
    for(auto [x,y]:ans)
    {
        cout << x << " " << y << "\n";

    }

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