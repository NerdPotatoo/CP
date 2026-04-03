#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define ll long long
template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
const int N = 1e6+9;
int a[N], l[N], r[N];
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n; cin >> n;
  for(int i = 1; i<=n; i++)
  {
    cin >> a[i];
  }

  o_set<int> s;
  for(int i = n; i>=1; i--)
  {
    r[i] = s.order_of_key(a[i]);
    s.insert(a[i]);
  }
  s.clear();
  for(int i = 1; i<=n; i++)
  {
    l[i] = s.size() - s.order_of_key(a[i]+1);
    s.insert(a[i]);
  }
  ll ans = 0;
  for(int i = 1; i<=n; i++)
  {
    ans += 1LL * l[i] * r[i];
  }
  cout << ans << '\n';
  return 0;
}