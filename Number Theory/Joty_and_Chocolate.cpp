#include<bits/stdc++.h>
#define ll long long
using namespace std;

int32_t main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll n, a, b, p,q;
	cin >> n >> a >> b >> p >> q;
	ll c = (a / __gcd(a,b)) * b;
	ll common = n/c, div_by_a = n/a, div_by_b = n/b;
	ll res = ((div_by_a - common) * p) + ((div_by_b - common) * q) + (common*max(p,q));
	cout << res << endl; 

}	