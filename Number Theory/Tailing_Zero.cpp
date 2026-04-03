#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e6;
vector<int> primes;
bool is_prime[N];
void seive() {
	is_prime[1] = 0;
	for(int i = 2; i<N; i++)
	{
		is_prime[i] = 1;
	}

	for(int i = 2; i*i<N; i++)
	{
		if(is_prime[i])
		{
			for(int j = i+i; j<N; j+=i)
			{
				is_prime[j] = 0;
			}
		}
	}
	for(int i = 2; i<N; i++)
	{
		if(is_prime[i]) primes.push_back(i);
	}
}
int32_t main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	seive();
	int t, cs = 0; cin >> t;
	while(t--)
	{
		ll n; cin >> n;
		ll nod = 1;
		for(auto p:primes)
		{
			if(1LL*p*p>n) break;
			int e = 0;
			while(n%p==0)
			{
				++e;
				n/=p;
			}
			nod *= (e+1);
		}
		if(n>1)
		{
			nod *= 2;
		}
		cout << "Case " << ++cs << ": " << nod-1 << endl;
	}	
}	