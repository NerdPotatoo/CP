#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5+9;
vector<pair<int,int>> g[N];
ll d[N];

void dfs(int u, int p)
{
	for(auto [v,w]:g[u])
	{
		if(v!=p)
		{
			d[v] = d[u] + w;
			dfs(v, u);
		}
	}
}
int32_t main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t; cin >> t;
	while(t--)
	{
		int n; cin >> n;
		for(int i = 1; i<n; i++)
		{
			int u, v, w;
			cin >> u >> v >> w;
			g[u].push_back({v,w});
			g[v].push_back({u,w});
		}

		d[1] = 0;
		dfs(1,0);
		int st = 0;
		ll mx_dis = 0;
		for(int i = 1; i<=n; i++)
		{
			if(mx_dis < d[i])
			{
				mx_dis = d[i];
				st = i;
			}
		}

		d[st] = 0;
		ll dis_st[n+1];
		dfs(st,0);
		int ed = 0;
		mx_dis = 0;
		for(int i = 1; i<=n; i++)
		{
			if(mx_dis<d[i])
			{
				mx_dis = d[i];
				ed = i;
			}
			dis_st[i] = d[i];
		}

		d[ed] = 0;
		dfs(ed,0);
		for(int i = 1; i<= n; i++)
		{
			cout << max(dis_st[i],d[i]) << ' '; 
		}
		cout << '\n';

		for(int i = 1; i<=n; i++)
		{
			g[i].clear();
			d[i] = 0;
		}
	}
}	