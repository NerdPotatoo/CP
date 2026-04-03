#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q, x, id;
    cin >> n >> q;
    multiset<int> s;
    for(int i = 0; i<n; i++)
    {
        cin >> x;
        s.insert(x);
    }

    while(q--)
    {
        cin >> id;
        if(id == 0)
        {
            cin >> x;
            s.insert(x);
        }
        else if(id == 1)
        {
            cout << *s.begin() << endl;
            s.erase(s.begin());
        }
        else{
            cout << *s.rbegin() << endl;
            auto it = s.end();
            it--;
            s.erase(it);
        }
    }
}