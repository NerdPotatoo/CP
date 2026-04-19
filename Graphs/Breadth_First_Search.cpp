#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 105, inf = 1e9;
vector<int> g[N];
bool vis[N];
vector<int> D(N,inf);
void bfs(int u)
{
	vis[u] = true;
	D[u] = 0;
	queue<int> q;
	q.push(u);
	while(!q.empty())
	{
		int nod = q.front();
		q.pop();
		for(auto v:g[nod])
		{
			vis[v] = true;
			if(D[nod] + 1 < D[v])
			{
				D[v] = D[nod]+1;
				q.push(v);
			}
		}
	} 
}
int32_t main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n; cin >> n;
	for(int i = 1; i<=n; i++)
	{
		int u,k,v;
		cin >> u >> k;
		while(k--)
		{
			cin >> v;
			g[u].push_back(v);
		}
	}
	bfs(1);
	for(int i = 1; i<=n; i++)
	{
		cout << i << " " << ((D[i]==inf)? -1 : D[i]) << endl;
	}
}	