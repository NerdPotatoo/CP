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
    int n, q, i,j;
    cin >> n >> q;
    string s, t;
    cin >> s >> t;
    vector<int> cnt(n+1);
    while(q--)
    {
        cin >> i >> j;
        cnt[i-1] += 1;
        cnt[j] -= 1;
    }

    for(int i = 1; i<n+1; i++) cnt[i] += cnt[i-1];
    for(int i = 0; i<n; i++)
    {
        if(cnt[i]&1)
        {
            swap(s[i],t[i]);
        }
    } 
    cout << s << '\n';
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