#include<bits/stdc++.h>
#define ll long long
using namespace std;

int32_t main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m, cs = 0;
	while(cin >> n >> m)
	{
		vector<bool> bad(10, false);
		while(m--)
		{
			int k;
			cin >> k;
			bad[k] = true;
		}


		queue<int> q;
		vector<bool> vis(n, false);
		vector<int> par(n), digit(n);
		for(int d = 1; d<10; d++)
		{
			int x = d%n;
			if(!bad[d] && !vis[x])
			{
				vis[x] = true;
				q.push(x);
				digit[x] = d;
				par[x] = -1;
			}
		}
		while(!q.empty())
		{
			int x = q.front();
			q.pop();
			for(int d = 0; d<10; d++)
			{
				int nxt_x = (x * 10 + d) % n;
				if(!bad[d] && !vis[nxt_x])
				{
					vis[nxt_x] = true;
					q.push(nxt_x);
					digit[nxt_x] = d;
					par[nxt_x] = x;
				}
			}
		}
		// return 0;
		cout << "Case " << ++cs << ": ";
		if(vis[0])
		{
			vector<int> path;
			int cur = 0;
			while(cur != -1)
			{
				path.push_back(digit[cur]);
				cur = par[cur];
			}
			reverse(path.begin(), path.end());
			for(auto x:path)
			{
				cout << x;
			}
			cout << endl;
		}
		else{
			cout << -1 << '\n';
		}
	}
}	