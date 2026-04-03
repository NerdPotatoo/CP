#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e4+9, M = 1e9+7;
int spf[N];
bool is_prime[N];
void seive() {
	is_prime[1] = 0;
	for(int i = 2; i<N; i++)
	{
		is_prime[i] = 1;
	}

	for(int i = 2; i<N; i++)
	{
		if(is_prime[i])
		{
			for(int j = i+i; j<N; j+=i)
			{
				is_prime[j] = 0;
			}
		}
	}
	for(int i = 2; i < N; i++)
	{
		spf[i] = i;
	}

	for(int i = 2; i < N;i++)
	{
		if(spf[i] == i)
		{
			for(int j = i; j<N; j+=i)
			{
				spf[j] = min(spf[j], i);
			}
		}
	}
}
int32_t main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	seive();
	int t; cin >> t;
	while(t--)
	{
		int x; cin >> x;
		vector<int> cnt(x+1,0);
		for(int i = 2; i <= x; i++)
		{
			int n = i;
			while(n>1)
			{
				int k = spf[n];
				cnt[k]++;
				n/=k;
			}
		}
		ll nod = 1;
		for(auto e:cnt)
		{
			if(e) nod = (nod%M * (e+1)%M)%M;
		}
		cout << nod << endl;

	}	
}	