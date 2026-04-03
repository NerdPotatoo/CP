#include<bits/stdc++.h>
#define ll long long
using namespace std;
int32_t main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t , c = 0; cin >> t;
	while(t--)
	{
		int num, n; cin >> n;
		vector<int> pf(100);
		vector<pair<int,int>> spf;
		num = n;
		while(n>1)
		{
			int m = n;
			for(int i = 2; i * i <= m; i++)
			{
				while(m%i == 0)
				{
					pf[i]++;
					m/=i;
				}
			}
			if(m>1) pf[m]++;
			n--;
		}
		cout << "Case " << ++c << ": " << num << " = "; 
		for(int i = 2; i<100; i++)
		{
			if(pf[i])
			{
				spf.push_back({i,pf[i]});
			}
			// cout << pf[i] << " ";
		}

		for(int i = 0; i<spf.size()-1; i++)
		{
			cout << spf[i].first << " (" << spf[i].second << ") * ";
		}
		cout << spf.back().first << " (" << spf.back().second << ")";
		cout << endl;
	}
	


}	