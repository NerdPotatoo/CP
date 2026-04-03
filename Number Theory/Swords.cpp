#include<bits/stdc++.h>
#define ll long long
using namespace std;

int32_t main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll n; cin >> n;
	vector<ll> a(n);
	ll mx = 0;
	for(auto &i:a)
	{
		cin >> i ;
		mx = max(i,mx);
	}
	ll gcd = 0;
	for(auto &i:a)
	{
		i = mx-i;
		gcd = __gcd(gcd,i);
	}

	ll res = 0;
	for(auto i:a)
	{
		res += (i/gcd);
	}
	cout << res << " " << gcd << endl;
}	