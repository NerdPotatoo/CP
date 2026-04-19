#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5+9;
vector<int> g[N];
bool cycle;
int col[N];

void dfs(int u)
{
	col[u] = 1;
	for(auto v:g[u])
	{
		if(col[v] == 0)
		{
			dfs(v);
		}
		else if(col[v] == 1)
		{
			cycle = true;
		}

	}
	col[u] = 2;
}
int32_t main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m; cin >> n >> m;
	for(int i = 1; i<=n; i++)
	{
		int u, v; cin >> u >> v;
		g[u].push_back(v);
	}
	cycle  = false;
	for(int i = 1; i<=n; i++) if(col[i] == 0) dfs(1);
	cout << (cycle ? "YES\n" : "NO\n");
}	