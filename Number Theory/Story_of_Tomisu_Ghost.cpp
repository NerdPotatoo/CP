#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1e5 + 9, mod = 10000019;
vector<int> primes;
bool is_prime[N];
void seive(){
	for(int i = 2; i < N; i++)
	{
		is_prime[i] = true;
	}
	for(int i = 2; i < N; i++)
	{
		if(is_prime[i])
		{
			for(int j = i + i; j < N; j += i)
			{
				is_prime[j] = false;
			}
		}
	}
	for(int i = 2; i < N; i++)
	{
		if(is_prime[i]) primes.push_back(i);
	}
}
int legendre(int a, int p)
{
	int ans = 0;
	while(a)
	{
		ans += a / p;
		a /= p;
	}
	return ans;
}

int binpow(int a, int b)
{
	int ans = 1;
	while(b)
	{
		if(b & 1) ans = 1LL * ans * a % mod;
		a = 1LL * a * a % mod;
		b >>= 1;
	}
	return ans;
}
int32_t main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	seive();
	int tc, cs = 0; cin >> tc;
	while(tc--)
	{
		int n, t; cin >> n >> t;
		int b = 1;
		bool ok = false;
		for(auto p : primes)
		{
			if(p > n) break;
			int f = legendre(n , p);
			int e = f / t;
			if(e > 0)
			{
				ok = true;
			}
			b = 1LL * b * binpow(p , e) % mod;
		}

		if(!ok) b  = -1;
		cout << "Case " << ++cs << ": " << b << endl;
	}
}	