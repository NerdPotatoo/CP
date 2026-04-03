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
    vector<int> a(n), mx(n), mn(n);
    for(auto &e:a) cin >> e;
    mn[n-1] = a[n-1]+1;
    mx[0] = a[0]-1;
    for(int i = 1; i<n; i++)
    {
        mx[i] = max(a[i-1],mx[i-1]);
    }
    for(int i = n-2; i>=0; i--)
    {

        mn[i] = min(a[i+1],mn[i+1]);
    }

    for(int i = 0; i<n; i++)
    {
        if(a[i] > mx[i] && a[i] < mn[i])
        {
            cout << i+1 << '\n';
            return;
        }
    }
    cout << "Humanity is doomed!\n";
}
int32_t main()
{
    fastIO;
    int T = 1;
    cin>>T;
    for(int cs = 1; cs <= T; cs++)
    {
        cout<<"Case "<<cs<< ": ";
        solve();
    }
    return 0;
}