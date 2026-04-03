#include<bits/stdc++.h>
#define ll long long
using namespace std;
int32_t main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll x;
	while(cin >> x && x!=0)
	{
		ll cnt = 0;
		cout << x << " : ";
		for(ll i = 2; i * i <= x; i++)
		{
			if(x%i==0)
			{
				cnt++;
				while(x%i==0){x/=i;}
			}
		}
		if(x>1) cnt++;
		cout << cnt << endl;
	}
}	