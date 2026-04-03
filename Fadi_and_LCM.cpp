#include<bits/stdc++.h>
#define ll long long
using namespace std;

int32_t main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll n; cin >> n;
	pair<ll,ll> p;
	for(ll i = 1; i * i <= n; i++)
	{
		if(n%i == 0)
		{
			if(__gcd(i,n/i) == 1)
			{
				p = {i,n/i};
			}
		}
	}
	cout << p.first << " " << p.second << endl;
}	