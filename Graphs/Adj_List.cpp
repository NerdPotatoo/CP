#include<bits/stdc++.h>
using namespace std;
const int N = 1e3;
// space complexity O(V+E) 
// (V = vertices, E = edges)
vector<int> g[N]; // unweighted graph
vector<pair<int,int>> g2[N]; // weighted graph
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    while(m--)
    {
        int u, v, wt;
        cin >> u >> v;
        // unweighted 
        g[u].push_back(v);
        g[v].push_back(u);

        // weighted
        g2[u].push_back({v,wt});
        g2[v].push_back({u,wt});
    }

    // printing
    for(int i = 1; i<=n; i++)
    {
        cout << i << " -> ";
        for(int j = 0; j<g[i].size(); j++)
        {
            cout << g[i][j] << ' ';
        }
        cout << '\n';
    }
}