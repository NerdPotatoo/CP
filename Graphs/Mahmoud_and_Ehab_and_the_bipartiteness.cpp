#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5+9;
vector<int> g[N];
int col[N];
bool vis[N];
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
	}
}
int32_t main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n; cin >> n;
	for(int i = 1; i <n; i++)
	{
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1);
	vector<int> red,blue;
	for(int i = 1; i<=n; i++)
	{
		if(col[i]) red.push_back(i);
		else blue.push_back(i);
	}

	ll ans = 0;
	for(auto u : red)
	{
		int can_add = blue.size();
		for(auto v:g[u])
		{
			if(find(blue.begin(),blue.end(),v) != blue.end()) can_add--;
		}
		ans += can_add;
	}
	cout << ans << endl;

}	