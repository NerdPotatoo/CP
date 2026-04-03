#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int q, x, val;
    cin >> q;
    set<int> s;
    while(q--)
    {
        cin >> x >> val;
        if(x == 1)
        {
            s.insert(val);
        }
        else if(x == 2)
        {
            s.erase(val);
        }
        else{
            if(s.find(val) != s.end()) cout << "Yes";
            else cout << "No";
            cout << endl;
        }
    }
}