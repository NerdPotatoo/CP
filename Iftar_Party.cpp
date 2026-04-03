#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll MAX = 1e18;

void solve()
{
	ll p, l;
	cin >> p >> l;
	ll cq = p-l;
	vector<ll> ans;
	for(ll i = 1 ; i * i <= cq; i++)
	{
		if(cq%i == 0)
		{
			if(i>l) ans.push_back(i);
			if(cq/i != i && cq/i >l) ans.push_back(cq/i);
		}
	}
	sort(ans.begin(), ans.end());
	if(ans.size() == 0)
	{
		cout << " impossible\n";
		return;
	}
	for(ll x : ans)
	{
		cout << ' ' << x;
	}
	cout << '\n';
}
int32_t main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t; cin >> t;
	for(int i = 1; i<=t; i++)
	{
		cout << "Case " << i << ":";
		solve();
	}
	
}
