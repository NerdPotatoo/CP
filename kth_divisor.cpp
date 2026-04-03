#include<bits/stdc++.h>
#define ll long long
using namespace std;

int32_t main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll n, k; cin >> n >> k;
	vector<ll> divisors ;
	for(ll i = 1; i*i <= n; i++)
	{
		if(n%i==0)
		{
			if(n/i != i) divisors.push_back(n/i);
			divisors.push_back(i); 
		}
	}
	sort(divisors.begin(), divisors.end());
	if(divisors.size() >= k)
	{
		cout << divisors[k-1] << '\n';
	}
	else{
		cout << -1 << '\n';
	}
}
