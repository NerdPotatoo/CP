#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5+9;
bool vis[N], found;
vector<int> g[N], cycle;
int par[N];

void dfs(int u, int p){
	if(found) return;
	vis[u] = true;
	par[u] = p;
	for(auto v : g[u])
	{
		if(found) return;
		if(!vis[v])
		{
			dfs(v,u);
		}
		else if (v != p){
			found = true;
			auto st = u;
			while(u != v)
			{
				cycle.push_back(u);
				u = par[u];
			}
			cycle.push_back(v);
			cycle.push_back(st);
			return;
		}	
	}
}
int32_t main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m; cin >> n >> m;
	for(int i = 1; i<=m; i++)
	{
		int u, v; cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	cerr << n << m;
	for(int i = 1; i<=n; i++)
	{
		if(!vis[i])
		{
			dfs(i,0);
		}
		if(found)
		{
			cout << cycle.size() << '\n';
			for(auto u:cycle)
			{
				cout << u << ' ';
			}
			cout << '\n';
			return 0;
		}
	}

	cout << "IMPOSSIBLE\n";
}	