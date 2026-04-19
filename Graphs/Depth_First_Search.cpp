#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 105;
int cnt = 0;
vector<int> g[N];
int vis[N], d[N], f[N];

void dfs(int u)
{
	vis[u] = 1;
	d[u] = ++cnt;
	// cout << u << ' '; 
	for(auto v:g[u])
	{
		if(!vis[v])
		{
			dfs(v);

		}
	}
	f[u] = ++cnt;
}
int32_t main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n; cin >> n;
	for(int i = 1; i <= n; i++)
	{
		int u, k; cin >> u >> k;
		while(k--)
		{
			int v; cin >> v;
			g[u].push_back(v);
		}
	}
	for(int u = 1; u <=n; u++){
		if(!vis[u]) dfs(u);
		// cout << u << "->";
		// for(auto v:g[u])
		// {
		// 	cout << v << ' ';
		// }
		// cout << endl;
	}

	for(int i = 1; i <= n; i++)
	{
		cout << i << " " << d[i] << " " << f[i] << '\n';
	}
}	