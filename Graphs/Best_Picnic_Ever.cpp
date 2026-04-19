#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e3+5;
int cnt[N], person[N];
bool vis[N];
vector<int> g[N];
void dfs(int u)
{
	vis[u] = true;
	cnt[u]++;
	for(auto v:g[u])
	{
		if(!vis[v]) dfs(v);
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
		for(int i = 1; i <= k; i++)
		{
			int x; cin >> x;
			person[i] = x;
		}
		while(m--)
		{
			int u, v; cin >> u >> v;
			g[u].push_back(v);
		}
		for(int i = 1; i<= k; i++)
		{
			for(int u= 1; u<=n; u++)
			{
				vis[u] = false;
			}
			dfs(person[i]);
		}
		int ans = 0;
		for(auto x:cnt)
		{
			if(x == k) ans++;
		}
		cout << "Case " << ++cs << ": " << ans << endl;
		for(int i = 1; i<=n; i++)
		{
			g[i].clear();
			cnt[i] = 0;
			person[i] = 0;
		}

	}
}	