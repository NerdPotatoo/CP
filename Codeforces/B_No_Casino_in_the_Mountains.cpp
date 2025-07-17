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
    cin >> n >> k;
    vector<int> a(n), d;
    for(auto &e:a) cin >>e;
    int cnt = 0;
    for(int i = 0; i<n; i++)
    {
        if(a[i] == 0) cnt++;
        else{
            if(cnt>0) d.push_back(cnt);
            while(i<n && a[i] == 1) i++;
            cnt = 0;
            i--;
        }
    }
    if(cnt>0)d.push_back(cnt);
    int res  = 0;
    for(auto x:d)
    {
        if(x == k) res++;
        else if(x>k)
        {
            // cout << x/(k+1) <<' ';
            res += ((x+1)/(k+1));
        }
    }
    cout << res << endl;
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