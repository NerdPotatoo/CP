#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll MAX = 1e18;
ll POW(ll a, ll b)
{
	ll res = 1;
	while(b--)
	{
		res *= a;
	}
	return res;
}
int32_t main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n; cin >> n;
	while(n--)
	{
		ll x; cin >> x;
		ll sod = 1, nod = 1,dist_prime, tot_prime = 0, lpf = 1e9, gpf = 0; 
		map<ll,ll> spf;
		// cout << x << " = ";
		for(ll i = 2; i*i <= x; i++)
		{
			if(x%i==0)
			{
				while(x%i == 0)
				{
					x/=i;
					spf[i]++;
				}
				lpf = min(lpf,i);
				gpf = max(gpf,i);
			}
			
		}
		if(x>1) {
			spf[x]++;
			lpf = min(lpf,x);
			gpf = max(gpf,x);
		}

		dist_prime = spf.size();
		for(auto [p,e]:spf)
		{
			nod *= (e+1);
			tot_prime += e;
			sod *= (POW(p,e+1)-1)/(p-1);
		}
		cout << lpf << " " << gpf << " " << dist_prime << " " << tot_prime << " " << nod <<" " << sod <<endl;
	}
	
}
