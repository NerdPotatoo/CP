#include<bits/stdc++.h>
#define ll long long
using namespace std;
int32_t main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll l, r;
	cin >> l >> r;
	cout << "YES" << endl;
	for(auto i = l; i<r; i+=2)
	{
		cout << i << " " << i+1 << endl;
	}

}	