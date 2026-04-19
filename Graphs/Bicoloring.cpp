#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 205;
bool is_bicolorable;
int col[N];
vector<int> g[N];

void dfs(int u,int c)
{
	col[u] = c;
	for(auto v: g[u])
	{
		if(col[v] == 0)
		{
			dfs(v, ((c==1)? 2:1));
		}
		else if(col[u] == col[v]){
			is_bicolorable = false;
		}
	}
}
int32_t main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	while(cin >> n && n > 0)
	{
		int m; cin >> m;
		while(m--)
		{
			int u, v;
			cin >> u >> v;
			u++, v++;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		is_bicolorable = true;
		for(int i = 1; i<=n; i++)
		{
			col[i] = 0;
		}
		for(int u = 1; u <= n; u++)
		{
			if(col[u] == 0) dfs(u, 1);
		}
		

		cout << ((is_bicolorable)? "BICOLORABLE." : "NOT BICOLORABLE.") << '\n';
		for(int i = 1; i<=n; i++)
		{
			g[i].clear();
		}
	}
}	