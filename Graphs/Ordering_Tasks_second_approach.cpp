#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 105;
vector<int> g[N], ord;
bool vis[N];
void dfs(int u)
{	
	vis[u] = true;
	for(auto v:g[u])
	{
		if(!vis[v])
		{
			dfs(v);
		}
	}
	ord.push_back(u);
}
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
		}

		for(int i = 1; i<=n; i++)
		{
			if(!vis[i]) dfs(i);
		}
		reverse(ord.begin(),ord.end());
		for(auto u:ord)
		{
			cout << u << ' ';
		}
		cout << '\n';

		for(int i = 1; i<=n; i++)
		{
			g[i].clear();
			vis[i] = false;
		}
		ord.clear();
	}
}	