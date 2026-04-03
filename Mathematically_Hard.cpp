#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e6+9;
int spf[N];
unsigned long long phi[N];
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
			for(int j = i; j < N; j+=i)
			{
				spf[j] = min(i,spf[j]);
			}	
		}
	}
	for(int i = 2; i < N; i++)
	{
		int x = i, res = 1;
		while(x>1)
		{
			int p = spf[x], pw = 1;
			while(x%p==0)
			{
				pw *= 1LL * p;
				x/=p;
			}
			res *= (pw/p) * (p-1);
		}
		phi[i] = 1LL * res * res;
	}
	for(int i = 3; i<N; i++)
	{
		phi[i] += phi[i-1];
	}
	int t, cs = 0; cin >> t;
	while(t--)
	{
		int a, b; cin >> a >> b;
		cout << "Case " << ++cs << ": " << (phi[b] - phi[a-1]) << endl;
	}
}	