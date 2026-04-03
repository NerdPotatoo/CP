#include<bits/stdc++.h>
#define ll long long
using namespace std;

int32_t main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t, cs = 0; cin >> t;
	while(t--)
	{
		ll n; cin >> n;
		cout << "Case " << ++cs << ": ";
		if(n&1)
		{
			cout << "Impossible" << '\n';
			continue;
		}
		ll x = n;
		while(x%2==0)
		{
			x/=2;
		}
		cout << x << " " << n/x << '\n';

	}
	
}	