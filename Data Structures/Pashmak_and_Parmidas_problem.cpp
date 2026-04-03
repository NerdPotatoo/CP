#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
const int N = 1e6+9;
int a[N], l[N], r[N];
template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n; cin >> n;
  for(int i = 1; i<=n; i++)
  {
  	cin >> a[i];
  }

  map<int,int> cnt;
  for(int i = 1; i<=n; i++)
  {
  	cnt[a[i]]++;
  	l[i] = cnt[a[i]];
  }
  cnt.clear();
  for(int i = n; i>=1; i--)
  {
  	cnt[a[i]]++;
  	r[i] = cnt[a[i]];
  }
  o_set<pair<int,int>> se;
  long long ans = 0;
  for(int i = n; i>=1; i--)
  {
  	ans += se.order_of_key({l[i],i});
  	se.insert({r[i],i});
  }
  cout << ans << endl;
  return 0;
}