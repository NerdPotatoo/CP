#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e7+9;
bool is_prime[N];
vector<int> primes;
vector<pair<int,int>> prime_pairs;
void seive() {
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

	for(int i = 2; i<N; i++)
	{
		if(is_prime[i]) primes.push_back(i);
	}
	for(int i = 0; i<primes.size()-1; i++)
	{
		if(primes[i] == primes[i+1]-2)
		{
			prime_pairs.push_back({primes[i],primes[i+1]});
		}
	}
}
int32_t main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	seive();
	int n;
	// cout << prime_pairs.size();
	while(cin>>n)
	{
		cout << "(" << prime_pairs[n-1].first << ", " << prime_pairs[n-1].second << ")\n";
	}
}	