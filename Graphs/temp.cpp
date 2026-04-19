#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e3+5;
bool vis[N];
int vis_cnt[N];
vector<int> g[N];
void dfs(int u)
{
	vis[u] = true;
	vis_cnt[u]++;
	for(auto v:g[u])
	{
		if(!vis[v])dfs(v);
	}
}
int32_t main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t, cs = 0; cin >> t;
	while(t--)
	{
		int k, n , m;
		cin >> k >> n >> m;
		vector<int> homes;
		for(int i = 1; i<=k; i++)
		{
			int x; cin >> x;
			homes.push_back(x);
		}
		while(m--)
		{
			int u, v; cin >> u >> v;
			g[u].push_back(v);
		}
		for(auto x:homes)
		{
			for(int i = 1; i<=n; i++)
			{
				vis[i] = false;
			}
			dfs(x);
		}
		int ans = 0;
		for(auto x:vis_cnt)
		{
			if(x == (int)homes.size()) ans++;
		}
		cout << "Case " << ++cs << ": " << ans << endl;
		for(int i = 1; i<=n; i++)
		{
			g[i].clear();
			vis_cnt[i] = 0;
			vis[i] = false;
		}

	}
}	