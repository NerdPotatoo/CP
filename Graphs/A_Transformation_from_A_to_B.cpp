#include<bits/stdc++.h>
using namespace std;
#define yes cout << "YES\n";
#define no cout << "NO\n";
#define ll long long
vector<ll> path;
ll a, b;
int dfs(ll a)
{
    path.push_back(a);
    if(a>b){
        path.pop_back();
        return  0;
    }
    if(a==b) return 1;

    if(dfs(2*a))
    {
        return 1;
    }
    if(dfs(10*a + 1))
    {
        return 1;
    }
    path.pop_back();
    return 0;
}
void solve()
{
    // CODE HERE
    cin >> a >> b;
    if(dfs(a))
    {
        yes
        cout << path.size() << '\n';
        for(auto x:path)
        {
            cout << x << ' ';
        }
        cout << '\n';
    }
    else{
        no
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}