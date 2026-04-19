#include<bits/stdc++.h>
#define ll long long
using namespace std;

int32_t main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m; cin >> n >> m;
	queue<int> q;
	map<int,int> d;
	for(int i = 1; i<=n; i++)
	{
		int x; cin >> x;
		q.push(x);
		d[x] = 0;
	}


	long long ans = 0;
	vector<int> v;
	while(!q.empty() && m)
	{
		int u = q.front();
		q.pop();
		if(d.find(u-1) == d.end() && m)
		{
			d[u-1] = d[u]+1;
			ans += d[u-1];
			q.push(u-1);
			v.push_back(u-1);
			m--;
		}
		if(d.find(u+1) == d.end() && m)
		{
			d[u+1] = d[u] + 1;
			ans += d[u+1];
			q.push(u+1);
			v.push_back(u+1);
			m--;
		}
	}
	cout << ans << '\n';
	for(auto x:v)
	{
		cout << x << ' ';
	}
	cout << '\n';

}	