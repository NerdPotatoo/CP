#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tt; cin >>tt;
  while(tt--)
  {
    int n; cin >> n;
    int a[n];
    for(int i = 0; i<n; i++)
    {
      cin >> a[i];
    }
    long long inv = 0;
    o_set<int> s;
    for(int i = n-1; i >= 0; i--)
    {
      
      inv += s.order_of_key(a[i]);
      s.insert(a[i]);
    }
    cout << inv << endl;
  }
  

  return 0;
}