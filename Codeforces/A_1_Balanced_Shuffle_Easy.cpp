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
    string s;
    cin >> s;

   int t = 0;
   vector<tuple<int,int,char>> v;
   for(int i = 0; i<s.size(); i++)
   {
        if(s[i] == ')')
        {
            v.push_back({t--,-i, ')'});
        }
        else{
            v.push_back({t++,-i,'('});
        }
   }
   sort(all(v));
   for(auto [x,y,z] : v)
   {
        cout <<z ;
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