#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5+9;
vector<int> g[N];
int consicutive[N], cat[N];
int ans, m;
bool vis[N];
void dfs(int u, int p)
{
	vis[u] = true;
	if(cat[u])
	{
		consicutive[u] = consicutive[p] + cat[u];
	}
	else{
		consicutive[u] = 0;
	}

	if(consicutive[u] > m)
	{
		return;
	}
	bool leaf = true;
	for(auto v:g[u])
	{
		if(!vis[v])
		{
			dfs(v,u);
			leaf = false;
		}
	}
	if(leaf) ans++;
}
int32_t main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n; cin >> n >> m;
	for(int i = 1; i<=n; i++)
	{
		cin >> cat[i];
	}

	for(int i = 1; i<n; i++)
	{
		int u, v; cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	ans = 0;
	dfs(1,0);

	cout << ans << '\n';
}	