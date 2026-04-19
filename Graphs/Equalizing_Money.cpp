#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e3+5;
vector<int> g[N];
bool vis[N];
int a[N], tot_person, tot_money;

void dfs(int u)
{
	vis[u] = true;
	tot_person++;
	tot_money += a[u];

	for(auto v:g[u])
	{
		if(!vis[v])
		{
			dfs(v);
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
		int n, m; cin >> n >> m;
		for(int i = 1; i<=n; i++)
		{
			cin >> a[i];
			vis[i] = false;
			g[i].clear();
		}
		while(m--)
		{
			int u, v; cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		set<int> s;
		bool ok = true;
		for(int i = 1; i<=n; i++)
		{
			if(!vis[i])
			{
				tot_money = 0, tot_person = 0;
				dfs(i);
				if(tot_money%tot_person == 0)
				{
					s.insert(tot_money/tot_person);
				}
				else{
					ok = false;
					break;
				}
			}
		}
		cout << "Case " << ++cs << ": ";
		if(ok && (int)s.size() == 1) cout << "Yes\n";
		else cout << "No\n";
	}
}	