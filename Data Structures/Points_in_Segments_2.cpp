#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e4+9;
int a[N], b[N], Q[N];
int p[3*N];
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

		for(int i = 0; i<n; i++)
		{
			a[i] = mp[a[i]];
			b[i] = mp[b[i]];
		}
		for(int i = 0; i<q; i++)
		{
			Q[i] = mp[Q[i]];
		}
		
		for(int i = 0; i<n; i++)
		{
			p[a[i]] += 1;
			p[b[i]+1] -= 1;
		}

		for(int i = 1; i<=id; i++)
		{
			p[i] += p[i-1];
		}
		cout << "Case " << ++cs << ": "<< endl;
		for(int i = 0; i<q; i++)
		{
			cout << p[Q[i]] << endl;
		}
		for(int i = 0; i<=id+1; i++)
		{
			p[i] = 0;
		}
	}
}	