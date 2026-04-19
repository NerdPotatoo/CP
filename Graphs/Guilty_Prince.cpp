#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 30;
string g[N];
int n, m, can_go;
bool vis[N][N];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
bool valid(int i, int j)
{
	return (i >= 0 && i < m && j >= 0 && j < n);
}

void dfs(int si, int sj)
{
	vis[si][sj] = true;
	can_go++;
	for(int k = 0; k < 4; k++)
	{
		int ci = si + dx[k];
		int cj = sj + dy[k];
		if(valid(ci,cj) && g[ci][cj] == '.' && !vis[ci][cj])
		{
			dfs(ci,cj);
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
		cin >> n >> m;
		for(int i = 0; i < m; i++)
		{
			g[i].clear();
			for(int j = 0; j < n; j++)
			{
				vis[i][j] = false;	
			}
			
		}
		
		int si, sj;
		for(int i = 0; i < m; i++)
		{
			cin >> g[i];
		}
		for(int i = 0; i < m; i++)
		{
			for(int j = 0; j < n; j++)
			{
				if(g[i][j] == '@')
				{
					si = i;
					sj = j;
				}
			}
		}
		can_go = 0;
		dfs(si,sj);

		cout << "Case " << ++cs << ": " <<can_go << '\n';
		
	}
}	