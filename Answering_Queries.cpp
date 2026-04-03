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
		int n, q;
		cin >> n >> q;
		int a[n];
		for(int i = 0; i<n; i++)
		{
			cin >> a[i];
		}

		ll sum = 0;
		for(int i = 0; i<n; i++)
		{
			sum += 1LL * a[i] * (n - (2 * i) - 1);
		}
		cout << "Case " << ++cs << ": \n";
		while(q--)
		{
			int ty; cin >> ty;

			if(ty)
			{
				cout << sum << '\n';
			}
			else{
				int x, v; cin >> x >> v;
				sum -= 1LL * a[x] * (n - (2 * x) - 1);
				a[x] = v;
				sum += 1LL * a[x] * (n - (2 * x) - 1);
			}
		}
	}
}	