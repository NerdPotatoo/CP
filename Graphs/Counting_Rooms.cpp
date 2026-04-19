#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1005;
string g[N];
int n, m, rooms;
bool vis[N][N];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

bool valid(int i, int j)
{
	return i >= 0 && i < n && j >= 0 && j < m;
}
void dfs(int si,int sj)
{	
	vis[si][sj] = true;
	for(int k = 0; k<4; k++)
	{	
		auto ci = si + dx[k];
		auto cj = sj + dy[k];
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
	cin >> n >> m;
	for(int i = 0; i<n; i++)
	{
		cin >> g[i];
	}
	rooms = 0;
	for(int i = 0; i<n; i++)
	{
		for(int j = 0; j<m; j++)
		{
			if(g[i][j] != '#' && !vis[i][j])
			{
				rooms++;
				dfs(i,j);
			}
		}
	}
	cout << rooms << endl;
}	