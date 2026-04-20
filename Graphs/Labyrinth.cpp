#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1005, inf = 1e9;
string g[N];
int n, m;
int d[N][N];
pair<int,int> par[N][N];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
bool valid(int i, int j)
{
	return i >= 0 && i < n && j >= 0 && j < m;
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
	pair<int,int> start, end;
	for(int i = 0; i<n; i++)
	{
		for(int j = 0; j<m; j++)
		{
			if(g[i][j] == 'A')
			{
				start = {i,j};
			}
			if(g[i][j] == 'B')
			{
				end = {i,j};
			}
		}
	}
	for(int i = 0; i<n; i++)
	{
		for(int j = 0; j<m; j++)
		{
			d[i][j] = inf;
		}
	}
	queue<pair<int,int>> q;
	q.push(start);
	d[start.first][start.second] = 0;
	while(!q.empty())
	{
		auto [i, j] = q.front();
		q.pop();

		for(int k = 0; k<4; k++)
		{
			int ci = i + dx[k];
			int cj = j + dy[k];
			if(valid(ci,cj) && g[ci][cj] != '#' && (d[i][j]+1 < d[ci][cj]))
			{
				d[ci][cj] = d[i][j] + 1;
				par[ci][cj] = {i,j};
				q.push({ci,cj});
				
			}
		}
	}
	auto [di,dj] = end;
	if(d[di][dj] != inf)
	{
		
		cout << "YES\n" << d[di][dj] << '\n';

		vector<pair<int,int>> path;
		auto cur = end;

		while(cur != start)
		{
			path.push_back(cur);
			cur = par[cur.first][cur.second];
		}
		path.push_back(start);
		reverse(path.begin(),path.end());

		for(int i = 0; i+1 < path.size(); i++)
		{
			int x = path[i].first - path[i+1].first;
			int y = path[i].second - path[i+1].second;
			if(x == 1)
			{
				cout << 'U';
			}
			else if(x == -1)
			{
				cout << 'D';
			}
			else if(y == 1)
			{
				cout << 'L';
			}
			else
			{
				cout << 'R';
			}
		}
		cout << '\n';

	}
	else
	{
	 	cout << "NO\n";
	} 
	 
}	