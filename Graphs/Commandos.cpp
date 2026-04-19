#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 105, inf = 1e9;
int n;
vector<int> g[N];
vector<int> bfs(int s)
{
	vector<int> d(n, inf);
	d[s] = 0;
	queue<int> q;
	q.push(s);
	while(!q.empty())
	{
		int u = q.front();
		q.pop();

		for(auto v : g[u])
		{
			if(d[u] + 1 < d[v])
			{
				d[v] = d[u] + 1;
				q.push(v);
			}
		}
	}

	return d;
}
int32_t main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t, cs = 0; cin >> t;
	while(t--)
	{
		int m; cin >> n >> m;
		while(m--)
		{
			int u, v;
			cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
		}

		int st, ed; cin >> st >> ed;
		auto ds = bfs(st);
		auto de = bfs(ed);

		int ans = 0;
		for(int i = 0; i < n; i++)
		{
			ans = max(ans, ds[i] + de[i]);
		}

		cout << "Case " << ++cs << ": " << ans << endl;

		for(int i = 0; i<n; i++)
		{

			g[i].clear();
		}
	}

}	