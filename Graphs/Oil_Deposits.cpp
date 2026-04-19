#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 105;
string g[N];
bool vis[N][N];
int n, m;
int dx[] = {0, -1,  0, 1,  -1, -1, 1, 1};
int dy[] = {1,  0, -1,  0,  1, -1, -1, 1};
bool valid(int i, int j)
{
	return i >= 0 && i < n && j >= 0 && j < m;
}
void dfs(int i, int j)
{
	vis[i][j] = true;
	for(int k = 0; k<8; k++)
	{
		int ni = i + dx[k];
		int nj = j + dy[k];
		if(valid(ni,nj) && (g[ni][nj] == '@') && (!vis[ni][nj]))
		{
			dfs(ni,nj);
		}
	}
}
int32_t main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	while(cin >> n >> m && n && m)
	{
		for(int i = 0; i<n; i++)
		{
			cin >> g[i];
		}
		int comp = 0;
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < m; j++)
			{
				if(g[i][j] == '@' && !vis[i][j]){
					
					dfs(i,j);
					comp++;
				}
			}
		}
		cout << comp << endl;
		for(int i = 0; i<n;i++)
		{
			for(int j = 0; j<m; j++)
			{
				vis[i][j] = false;
			}
		}
	}
	

}	