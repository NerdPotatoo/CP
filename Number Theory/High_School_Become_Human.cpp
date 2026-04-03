#include<bits/stdc++.h>
#define ll long long
using namespace std;

int32_t main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int x, y; cin  >> x >> y;
	double L = y * log(x);
	double R = x * log(y);

	if(L > R)
	{
		cout << ">" << endl;
	}
	else if(L < R)
	{
		cout << "<" << endl;
	}
	else{
		cout << "=" << endl;
	}
}	