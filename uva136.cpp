#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll MAX = 1e18;
int32_t main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<ll> ugly_nums;

	ll p2 = 1;
	for(ll x = 0; p2<=MAX; x++, p2*=2)
	{
		ll p3 = 1;
		for(ll y = 0; p2 * p3 <= MAX; y++, p3*=3)
		{
			ll p5 = 1;
			for(ll z = 0; p2 * p3 * p5 <= MAX; z++, p5*=5)
			{
				ugly_nums.push_back(p2*p3*p5);
			}
		}
	}
	sort(ugly_nums.begin(), ugly_nums.end());

	cout << "The 1500'th ugly number is " << ugly_nums[1500-1] << ".";
	
}
