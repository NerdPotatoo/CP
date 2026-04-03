#include<bits/stdc++.h>
using namespace std;

#define ll long long
const ll MAX = 1e10;
const int N = 1e5 + 9;
int spf[N];
vector<ll> v[N];

int32_t main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	for(int i = 2; i < N; i++)
	{
		spf[i] = i;
	}
	for(int i = 2; i < N; i++)
	{
		if(spf[i] == i)
		{
			for(int j = i; j < N; j += i)
			{
				spf[j] =  min(spf[j],i);
			}
		}
	}
	for(int i = 1; 1LL * i * i <= MAX; i++)
	{
		int x = i;
		int nod = 1;
		while(x > 1)
		{
			int p = spf[x], e = 0;
			while(x % p == 0)
			{
				e++;
				x /= p;
			}
			nod *= ((2 * e) + 1);
		}
		v[nod].push_back(1LL * i * i);
	}
	int q; cin >> q;
	while(q--)
	{
		int k; ll l, r; cin >> k >> l >> r;
		int ans = upper_bound(v[k].begin(), v[k].end(), r) - lower_bound(v[k].begin(), v[k].end(), l);
		cout << ans << '\n';
	}
}	