#include<bits/stdc++.h>
#define ll long long
using namespace std;
int32_t main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll n, gcd = 0; cin >> n;
	for(int i = 1; i<=n; i++)
	{
		ll x; cin >> x;
		gcd = __gcd(x,gcd);
	}
	ll cnt = 0;
	for(ll i = 1; i*i <= gcd; i++)
	{
		if(gcd%i==0)
		{
			cnt++;
			if(gcd/i != i) cnt++;
		}
	}
	cout << cnt << '\n';
}	
