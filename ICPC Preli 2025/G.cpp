#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int t;
    cin >> t;
    while(t--)
    {
        string s;
        cin >> s;
        int cnt = 0, len = s.size();
        for(int i = 0; i<s.size()-1; i++)
        {
            if(s[i] == '\\' && s[i+1] == '0')
            {
                // cout << "yes" <<endl ;
                cnt++;
                len = min(i,len);
            }
        }
        len = min(len,(int)s.size() - cnt + 1); 
        cout << s.size() - cnt + 1 <<  " " << len << '\n';
    }
 
 return 0;
}