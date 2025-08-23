#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--)
    {
        int ok = 0;
        char c;
        for(int i = 0; i<8; i++)
        {
            int cnt = 0;
            for(int j = 0; j<8; j++)
            {
                cin >> c;
                if(c == 'R') cnt++;
            }
            if(cnt == 8) ok = 1;
        }
        if(ok) cout << "R" << '\n';
        else cout << "B" << '\n';
    }
}