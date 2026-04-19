#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int inf = 1e9;
int32_t main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int ed, cs = 0; 
	while(cin >> ed && ed)
	{
		int u, v;
		map<int,vector<int>> g;
		set<int> nodes;
		while(ed--)
		{
			cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
			nodes.insert(u);
			nodes.insert(v);
		}
		int st,ttl;
		while(cin >> st >> ttl && !(st == 0 && ttl == 0))
		{
			map<int,int> d;
			for(auto u:nodes)
			{
				d[u] = inf;
			}
			d[st] = 0;
			queue<int> q;
			q.push(st);
			while(!q.empty())
			{
				int u = q.front();
				q.pop();
				for(auto v:g[u])
				{
					if(d[u] + 1 < d[v])
					{
						d[v] = d[u] + 1;
						q.push(v);
					}
				}
			}

			int ans = 0;
			for(auto u : nodes)
			{
				if(d[u] > ttl) ans++;
			}
			cout << "Case " << ++cs << ": " << ans << " nodes not reachable from node " << st << " with TTL = " << ttl << ".\n";
		}

	}
}	