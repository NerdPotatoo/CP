#include<bits/stdc++.h>
using namespace std;

char grid[1005][1005];
int n,m;
void dfs(int i, int j)
{
    if(i<0 || j<0 || j==m || i == n) return;
    if(grid[i][j] == '#') return;
    grid[i][j] = '#';
    dfs(i,j+1);
    dfs(i,j-1);
    dfs(i+1,j);
    dfs(i-1,j);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<m; j++)
        {
            cin >> grid[i][j];
        }
    }
    int cnt = 0;
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<m; j++)
        {
            if(grid[i][j] != '#')
            {
                cnt++;
                dfs(i,j);
            }
        }
    }
    cout << cnt << endl;
}