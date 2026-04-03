#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e4+9;
int a[N], b[N];
int32_t main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt, cs = 0; cin >> tt;
	while(tt--)
	{
		int n, q; cin >> n >> q;
		set<int> all;
		for(int i = 0; i<n; i++)
		{
			cin >> a[i] >> b[i];
			all.insert(a[i]);
			all.insert(b[i]);
		}
		int Q[q];
		for(int i = 0; i<q; i++)
		{
			cin >> Q[i];
			all.insert(Q[i]);
		}		

		map<int,int> mp;
		int id = 0;
		for(auto x:all)
		{
			mp[x] = ++id;
		}
	}
}	