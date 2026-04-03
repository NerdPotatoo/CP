#include<bits/stdc++.h>
#define ll long long
using namespace std;

int32_t main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t, cs = 0; cin >> t;
	while(t--)
	{
		string a; cin >> a;
		ll b; cin >> b;
		abs(b);
		if(a[0] == '-')
		{
			a = a.substr(1);
		}
		// cout << a << endl;
		ll ans = 0;
		for(ll i = 0; i<a.size(); i++)
		{
			ans = (ans*10 + (a[i] - '0')) % b;
		}
		cout << "Case " << ++cs << ": ";
		if(ans == 0) {
			cout << "divisible" << '\n';
		}
		else {
			cout << "not divisible" << '\n';
		}
	}
}	