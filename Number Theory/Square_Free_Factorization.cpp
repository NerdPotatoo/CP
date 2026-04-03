#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e6+9;
int spf[N];
int32_t main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	for(int i = 2; i < N; i++)
	{
		spf[i] = i;
	}
	for(int i = 2; i < N; i++)
	{
		if(spf[i] == i)
		{
			for(int j = i; j < N; j += i)
			{
				spf[j] = min(spf[j], i);
			}
		}
	}
	int t; cin >> t;
	while(t--)
	{
		int n; cin >> n;
		int expo = 0;
		while(n>1)
		{
			int p = spf[n];
			int e = 0;
			while(n % p == 0)
			{
				e++;
				n /= p;
			}
			expo = max(expo,e);
		}
		cout << expo << '\n';
	} 
}	