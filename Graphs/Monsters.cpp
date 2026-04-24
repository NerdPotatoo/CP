#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1005, inf = 1e9;
string g[N];
bool can_go[N][N];
pair<int,int> par[N][N];
int n, m;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
bool valid(int i, int j)
{
	return i >= 0 && i < n && j >= 0 && j < m;
}
vector<vector<int>> bfs(vector<pair<int,int>> start)
{

	queue<pair<int,int>> q;
	vector<vector<int>> d(n, vector<int> (m,inf));
	for(auto [i,j]:start)
	{
		q.push({i,j});
		d[i][j] = 0;
	}

	while(!q.empty())
	{
		auto [i,j] = q.front();
		q.pop();
		for(int k = 0; k < 4; k++)
		{
			int ci = i + dx[k];
			int cj = j + dy[k];
			if(valid(ci,cj) && g[ci][cj] != '#' && d[i][j] + 1 < d[ci][cj])
			{
				d[ci][cj] = d[i][j] + 1;
				q.push({ci,cj});
			}
		}
	}
	return d;
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
	vector<pair<int,int>> starting, monsters;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			if(g[i][j] == 'A')
			{
				starting.push_back({i,j});
			}
			else if(g[i][j] == 'M')
			{
				monsters.push_back({i,j});
			}
		}
	}

	auto dis_A = bfs(starting);
	auto dis_M = bfs(monsters);
	for(int i = 0; i<n; i++)
	{
		for(int j = 0; j<m; j++)
		{

			can_go[i][j] = ((g[i][j] != '#') && (dis_A[i][j] < dis_M[i][j]));
		}
	}

	queue<pair<int,int>> q;
	vector<vector<int>> d(n, vector<int> (m, inf));
	pair<int,int> start = starting[0];
	q.push(start);
	d[start.first][start.second] = 0;
	while(!q.empty())
	{
		auto [i,j] = q.front();
		q.pop();
		for(int k = 0; k<4; k++)
		{
			int ci = i + dx[k];
			int cj = j + dy[k];
			if(valid(ci,cj) && can_go[ci][cj] && d[i][j] + 1 < d[ci][cj])
			{
				d[ci][cj] = d[i][j] + 1;
				par[ci][cj] = {i,j};
				q.push({ci,cj});
			}
		}
	}
	for(int i = 0; i<n; i++)
	{
		for(int j = 0; j<m; j++)
		{
			if(i == 0 || i == n-1 || j == 0 || j == m-1)
			{
				if(d[i][j] != inf)
				{
					cout << "YES\n";
					cout << d[i][j] << '\n';
					vector<pair<int,int>> path;
					auto cur = make_pair(i,j);
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
						if(y == 1)
						{
							cout << "L";
						}
						else if(y == -1)
						{
							cout << "R";
						}
						else if(x == 1)
						{
							cout << "U";
						}
						else{
							cout << "D";
						}

					}
					return 0;

				}
			}
		}
	}
	cout << "NO\n";
		
	
	
}		