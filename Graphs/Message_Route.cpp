#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5+9;
vector<int> g[N];
int P[N];
bool vis[N];
void bfs(int u, int p)
{
	vis[u] = true;
	P[u] = p;
	queue<int> q;
	q.push(u);
	while(!q.empty())
	{
		int nod = q.front();
		q.pop();
		for(int v : g[nod])
		{
			if(!vis[v])
			{
				vis[v] = true;
				P[v] = nod;
				q.push(v);
			}
		}
	}
}

int32_t main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m; cin >> n >> m;
	for(int i =1 ; i <= n; i++)
	{
		P[i] = i;
	}
	while(m--)
	{
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	bfs(1,1);
	if(P[n] == n)
	{
		cout << "IMPOSSIBLE\n";
		return 0;
	}
	vector<int> path;
	path.push_back(n);
	int x = n;
	while(P[x] != x)
	{
		path.push_back(P[x]);
		x = P[x];
	}
	cout << path.size() << endl;
	for(auto it = path.rbegin(); it != path.rend(); it++)
	{
		cout << *it << ' ';
	}
}	