#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5+9;
vector<int> g[N];
int dep[N], par[N], required_len;
bool vis[N], found;

void dfs(int u, int p)
{
	if(found) return;
	par[u] = p;
	vis[u] = true;
	for(int v : g[u])
	{
		if(found) return;
		if(!vis[v])
		{
			dep[v] = dep[u]+1;
			dfs(v,u);
		}
		else{
			int cycle_len = dep[u] - dep[v] + 1;
			if(cycle_len >= required_len)
			{
				found = true;
				cout << 2 << '\n';
				cout << cycle_len << '\n';
				while(u != v)
				{
					cout << u << ' ';
					u = par[u]; 
				}
				cout << v << '\n';
				return;
			}
		}
	}
}

int col[N];
void dfs2(int u)
{

	vis[u] = true;
	for(int v:g[u])
	{
		if(!vis[v])
		{
			dfs2(v);
		}
	}
	set<int> not_allowed;
	for(int v:g[u])
	{
		if(col[v])
		{
			not_allowed.insert(col[v]);
		}
	}

	int color = 1;
	while(not_allowed.find(color) != not_allowed.end()) color++;
	col[u] = color;
}
vector<int> colored_nodes[N];
int32_t main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m; cin >> n >> m;
	while(m--)
	{
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	int k = 1;
	while(k * k < n)
	{
		k++;
	}
	required_len = k;
	found = false;
	dfs(1, 0);

	if(found) return 0;	
	// cout << "NO Cycle\n";
	memset(vis, false, sizeof(vis));
	dfs2(1);

	for(int i = 1; i<=n; i++)
	{
		colored_nodes[col[i]].push_back(i);
	}
	// cout << endl;

	for(int i = 1; i <= n; i++)

	{
		if(colored_nodes[i].size() >= required_len)
		{
			cout << 1 << '\n';
			for(int j = 0; j < required_len; j++)
			{
				cout << colored_nodes[i][j] << ' ';
			}
			cout << endl;
			return 0;
		}
	}



	
}	