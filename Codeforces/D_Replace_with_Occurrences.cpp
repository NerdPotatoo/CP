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
    vector<int> a(n), fq(n+1, 0);
    vector<vector<int>> idx(n+1);
    vector<int> b(n);
    for(int i = 0; i<n; i++){
        cin >> a[i];
        fq[a[i]]++;
        idx[a[i]].push_back(i);
    }
    int val = 0;
    for(int i = 1; i<=n; i++)
    {   
        if(fq[i] == 0) continue;
        else if(fq[i]%i != 0)
        {
            cout << -1 << '\n';
            return;
        }
        for(int j = 0; j<fq[i]; j++)
        {
            if(j%i == 0)
            {
                val++;
            }
            b[idx[i][j]] = val;
        }
    }
    for(int i :b)
    {
        cout<< i << ' ';
    }
    cout << '\n';
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