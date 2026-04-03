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
		ll n, sum = 0;
		cin >> n;
		for(ll i = 1; i * i <= n; i++)
		{
			if(n%i==0)
			{
				sum += i;
				if(n/i != i) sum += n/i;
			}
		}
		sum -= n;
		cout << sum << '\n';
	}
}	