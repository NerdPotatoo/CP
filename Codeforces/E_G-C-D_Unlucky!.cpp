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
    vector<int> pre(n), suf(n);
    for(int &e:pre) cin >> e;
    for(int &e:suf) cin >> e;

    if(pre[n-1] == suf[0]){
        for(int i = 1; i<n; i++)
        {
           if((pre[i-1]%pre[i] != 0) ||(suf[i]%suf[i-1] != 0)) 
           {
            no
            return;
           }
        }
        for(int i = 0; i<n; i++)
        {
            if(__gcd(pre[i],suf[i]) != pre[n-1] || (i+1<n && __gcd(pre[i],suf[i+1]) != pre[n-1]))
            {
                no
                return;
            }
        }
        yes
    }
    else{
        no
    }


}
int32_t main()
{
    fastIO;
    int T = 1;
    cin>>T;
    for(int cs = 1; cs <= T; cs++)
    {
        // cout<<"Case "<<cs<< ": ";
        solve();
    }
    return 0;
}