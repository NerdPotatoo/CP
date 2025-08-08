#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int q;
    ll n, x;
    cin >> q;
    vector<ll> a;
    while(q--)
    {
        
        cin >> n;
        if(n == 2) a.pop_back();
        else{
            cin >> x;
            if(n == 0)
            {
                a.push_back(x);
            }
            if(n==1 && a.size()){
                cout << a[x] << '\n';
            }
        }
    }
}