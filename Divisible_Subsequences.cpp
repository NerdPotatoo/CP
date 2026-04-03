#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e4+11;

int a[N];
ll pref[N];
int32_t main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t; cin >> t;
	while(t--)
	{
		int d, n;
		cin >> d >> n;
		for(int i = 1; i <= n; i++)
		{
			cin >> a[i];
		}	
		for(int i = 1; i <= n; i++)
		{
			pref[i] = pref[i-1] + a[i];
		}

		map<int,int> cnt;
		cnt[0] = 1;
		ll ans = 0;
		for(int i = 1; i <= n; i++)
		{
			ans += cnt[pref[i] % d];
			cnt[pref[i] % d]++;
		}
		cout << ans << '\n';
	}
	
}	