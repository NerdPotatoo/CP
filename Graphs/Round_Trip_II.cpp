#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5+9;
bool found;
vector<int> g[N], cycle;
int col[N], par[N];

void dfs(int u){
	if(found) return;
	col[u] = 1;
	for(auto v : g[u])
	{
		if(found) return;
		if(col[v] == 0)
		{
			par[v] = u;
			dfs(v);
		}
		else if (col[v] == 1){
			found = true;
			auto st = u;
			while(u != v)
			{
				cycle.push_back(u);
				u = par[u];
			}
			cycle.push_back(v);
			cycle.push_back(st);
			reverse(cycle.begin(),cycle.end());
			return;
		}	
	}
	col[u] = 2;
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
	}
	for(int i = 1; i<=n; i++)
	{
		if(!col[i])
		{
			dfs(i);
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
		
	}

	cout << "IMPOSSIBLE\n";
}	