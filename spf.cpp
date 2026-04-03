#include<bits/stdc++.h>
using namespace std;

int32_t main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;

	vector<int> v;
	for(int i = 2; i * i <= n; i++)
	{
		while(n%i ==0)
		{
			n/=i;
			v.push_back(i);
		}
	}	
	if(n>1) v.push_back(n);
	for(auto x:v) cout << x << ' ';
}