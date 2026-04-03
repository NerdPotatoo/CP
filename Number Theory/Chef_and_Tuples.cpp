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
		int n, a, b, c;
		cin >> n >> a >> b >> c;
		vector<int> d;
		for(int i = 1; i * i <= n; i++)
		{
			if(n%i==0)
			{
				d.push_back(i);
				if(i != n/i ) d.push_back(n/i);
			}
		}
		int cnt = 0;
		for(auto x:d)
		{
			if(x<=a)
			{
				for(auto y:d)
				{
					if(y<=b)
					{
						if(n%(1LL* x * y) == 0)
						{
							int z = n/(x*y);
							if(z <= c) cnt++; 
						}
					}
				}
			}
		}
		cout << cnt << endl;

	}
	
}
