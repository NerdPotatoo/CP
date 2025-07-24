#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m, a, b;
    cin >> n >> m >> a >> b;
    int ans = n*a;
    int l = n/m;
    int r = n%m;
    ans = min (ans, ((l*b)+ min((r*a),b)));
    cout << ans << '\n';

}
