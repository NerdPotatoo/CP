#include<bits/stdc++.h>
#define ll long long
using namespace std;
int32_t main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t; cin >> t;
	while(t--)
	{
		ll a, b;
		cin >> a >> b;
		ll g = __gcd(a,b);
		while(b/=g)
		{
			g = __gcd(a,b);
			if(g==1) break;
		}
		if(b == 1)cout << "Yes\n";
		else cout << "No\n";
	}
	
}	