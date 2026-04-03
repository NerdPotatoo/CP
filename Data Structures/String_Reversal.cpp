#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n; cin >> n;
	string s, r;
	cin >> s;
	r = s;
	reverse(r.begin(),r.end());
	map<char,vector<int>> ocur_s, ocur_r;
	for(int i = 0; i<n; i++)
	{
		ocur_s[s[i]].push_back(i);
		ocur_r[r[i]].push_back(i);
	}
	int p[n];
	for(char c = 'a'; c <= 'z'; c++)
	{
		for(int i = 0; i<(int)ocur_s[c].size(); i++)
		{
			p[ocur_r[c][i]] = ocur_s[c][i];
		}
	}

	// for(int i = 0; i<n; i++)
	// {
	// 	cout << p[i] << ' ';
	// }

	o_set<int> se;
	long long ans = 0;
	for(int i = n-1; i>=0; i--)
	{
		ans += se.order_of_key(p[i]);
		se.insert(p[i]);
	}
	cout << ans << '\n';
  return 0;
}