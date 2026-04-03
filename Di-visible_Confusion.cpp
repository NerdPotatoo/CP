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
		int n; cin >> n;
		int a[n + 1];
		for(int i = 1; i <= n; i++)
		{
			cin >> a[i];
		}
		bool ok = true;
		for(int i = 1; i <= min(n,21); i++)
		{
			bool can_erase = false;
			for(int j = 1; j <= i; j++)
			{
				if(a[i] % (j+1) != 0)
				{
					can_erase = true;
				}
			}
			if(!can_erase)
			{
				ok = false;
				break;
			}
		}
		if(ok) cout << "YES\n";
		else cout << "NO\n";
	}
}	