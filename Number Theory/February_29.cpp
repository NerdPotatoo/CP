#include<bits/stdc++.h>
#define ll long long
using namespace std;

int leap_year_prefix(int year)
{
	int ans = year / 4;
	ans -= year / 100;
	ans += year / 400;
	return ans;
}
int cnt_leap_days(int sYear, int eYear)
{
	return (leap_year_prefix(eYear) - leap_year_prefix(sYear - 1));
}
int32_t main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t, cs = 0; cin >> t;
	while(t--)
	{
		string sMonth, eMonth;
		char dummy;
		int sDate, sYear, eDate, eYear;
		cin >> sMonth >> sDate >> dummy >> sYear;
		cin >> eMonth >> eDate >> dummy >> eYear;
		// cout << sMonth << " " << sDate << " " << sYear << endl; 
		// cout << eMonth << " " << eDate << " " << eYear << ed;; 
		if(sMonth == "January" || sMonth == "February"){}
		else sYear++;
		if(eMonth == "January" || (eMonth == "February" && eDate < 29)){
			eYear--;
		}

		cout <<"Case "<< ++cs << ": " << cnt_leap_days(sYear,eYear) << endl;
	}
}	
