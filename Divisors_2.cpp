#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e6;
int d[N+1];
bool ok[N];
int32_t main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	for(int i = 1; i <= N; i++)
	{
		for(int j = i; j <= N; j += i)
		{
			d[j]++;
		}
	}
	for(int i = 1; i <= N; i++)
	{
		// cout << d[i] << ' ';
		ok[i] = true;
	}

	for(int m = 1; m <= N; m++)
	{
		for(int n = m; n <= N; n += m)
		{
			if(d[n] % d[m] != 0)
			{
				ok[n] = false;
			}
		}
	}
	vector<int> ans;
	for(int i = 1; i <= N; i++)
	{
		if(ok[i] && d[i] > 3) ans.push_back(i);
	}
	for(int i = 107; i <= ans.size(); i += 108)
	{
		cout << ans[i] << '\n';
	}
}	
