#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5+5, inf = 1e9;
int ans[N], a[N], n;
vector<int> g[N];
void solve(vector<int> even,vector<int> odd)
{
	vector<int> d(n+1, inf);
	queue<int> q;
	for(auto s:even)
	{
		q.push(s);
		d[s] = 0;
	}

	while(!q.empty())
	{
		int u = q.front();
		q.pop();
		for(auto v:g[u])
		{
			if(d[u] + 1 < d[v])
			{
				d[v] = d[u] + 1;
				q.push(v);
			}
		}
	}

	for(auto u:odd)
	{
		ans[u] = d[u];
	}
}

int32_t main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	vector<int> even, odd;
	for(int i = 1; i<=n; i++)
	{
		cin >> a[i];
		if(a[i]&1) odd.push_back(i);
		else even.push_back(i);
	}

	for(int i = 1; i <= n; i++)
	{
		int j = i - a[i];
		if(j >= 1) g[j].push_back(i);
		j = i + a[i];
		if(j <= n) g[j].push_back(i);
	}

	for(int i = 1; i <= n; i++)
	{
		ans[i] = inf;
	}

	solve(even,odd);
	solve(odd,even);


	for(int i = 1; i<=n; i++)
	{
		cout << ((ans[i] == inf)? -1 : ans[i]) << ' ';
	}
	cout << endl;

}	