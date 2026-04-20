#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 105;
vector<int> g[N];
int indeg[N];
int32_t main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	while(cin >> n >> m && n)
	{
		while(m--)
		{
			int u, v;
			cin >> u >> v;
			g[u].push_back(v);
			indeg[v]++;
		}

		queue<int> q;
		for(int i = 1; i<=n; i++)
		{
			if(!indeg[i]) q.push(i);
		}
		vector<int> ord;
		while(!q.empty())
		{
			int u = q.front();
			ord.push_back(u);
			q.pop();
			for(auto v:g[u])
			{
				indeg[v]--;
				if(indeg[v] == 0)
				{
					q.push(v);
				}
			}
		}
		for(auto u:ord)
		{
			cout << u << ' ';
		}
		cout << '\n';

		for(int i = 1; i<=n; i++)
		{
			g[i].clear();
			indeg[i] = 0;
		}
	}

}	