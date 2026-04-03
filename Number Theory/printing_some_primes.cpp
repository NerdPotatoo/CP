#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e8;
vector<int> p;
bitset<N> is_prime;
int32_t main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	is_prime[1] = true;
	for(int i = 2; i*i<N; i++)
	{
		if(is_prime[i] == 0)
		{
			for(int j = i+i; j<N; j+=i)
			{
				is_prime[j] = 1;
			}
		}
	}
	for(int i = 2; i<N; i++)
	{
		if(is_prime[i] == 0) p.push_back(i);
	}
	// cout << p.size() << ' ';
	for(int i = 0; i<p.size(); i+=100)
	{
		cout << p[i] << endl;
	}
}	
