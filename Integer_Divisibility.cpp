#include<bits/stdc++.h>
 #define ll long long
 using namespace std;
 
 int32_t main()
 {
 	ios::sync_with_stdio(false);
 	cin.tie(nullptr);
 	int t, cs = 0; cin >> t;
 	while(t--)
 	{
 		int n, d;
 		cin >> n >> d;
 		int cnt = 1, rem = d % n;
 		while(rem)
 		{
 			cnt++;
 			rem = (rem * 10 + d)%n;
 		}
 		cout << "Case " << ++cs << ": " << cnt << endl;
 	}
 }	 