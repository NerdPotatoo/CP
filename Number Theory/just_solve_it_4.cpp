#include<bits/stdc++.h>
#define ll long long
using namespace std;

int32_t main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll n, m, l, r;

	cin >> n >> m >> l >> r;

	ll g = __gcd(n,m);
	ll lcm = (n / g) * m;
	ll ans = (r/lcm) - ((l-1)/lcm);
	cout << ans << endl;
	// cout << lcm << endl;

}	