#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5+9;
vector<int> g[N], indeg(N);
int32_t main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m; cin >> n >> m;
	while(m--)
	{
		int u, v; cin >> u >> v;
		g[u].push_back(v);
		indeg[v]++;

	}

	queue<int> q;
	for(int i = 1; i<=n; i++)
	{
		if(!indeg[i]) q.push(i);
	}
	vector<int> ord;
	while(!q.empty())
	{
		auto u = q.front();
		ord.push_back(u);
		q.pop();

		for(auto v:g[u])
		{
			indeg[v]--;
			if(!indeg[v])
			{
				q.push(v);
			}
		}
	}
	if(ord.size() != n) {
		cout << "IMPOSSIBLE\n" ;
		return 0;
	}
	for(auto u:ord)
	{
		cout  << u <<  ' '; 
	}

	cout << '\n';
}	