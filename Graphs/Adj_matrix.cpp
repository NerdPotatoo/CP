#include<bits/stdc++.h>
using namespace std;
const int N = 1e3;
int g[N][N]; // space complexity O(N^2)
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    while(m--)
    {
        int u, v;
        cin >> u >> v;
        g[u][v] = 1; // if weighted then put weight instead of 1
        g[v][u] = 1;
    }


    for(int i = 1; i<=n; i++)
    {
        for(int j = 1; j<=n; j++)
        {
            cout << g[i][j] << ' ';
        }
        cout << '\n';
    }
}