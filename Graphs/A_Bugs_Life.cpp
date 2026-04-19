#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2005;
vector<int> g[N];
bool vis[N], sus;
int col[N];
void dfs(int u)
{
	vis[u] = true;
	for(int v:g[u])
	{
		if(!vis[v])
		{
			col[v] = col[u]^1;
			dfs(v);
		}
		else{
			if(col[v] == col[u])
			{
				sus = true;
			}
		}
	}
}
int32_t main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t, cs = 0; cin >> t;
	while(t--)
	{
		int n, m;
		cin >> n >> m;
		while(m--)
		{
			int u, v;
			cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		sus = false;
		for(int i = 1; i<=n; i++)
		{
			if(!vis[i])
			{
				dfs(i);
			}
		}
		cout << "Scenario #"  << ++cs << ":\n";
		cout << ((sus)? "Suspicious bugs found!\n" : "No suspicious bugs found!\n");
		for(int i = 1; i<=n; i++)
		{
			g[i].clear();
			vis[i] = false;
			col[i] = 0;
		}


	}
}	