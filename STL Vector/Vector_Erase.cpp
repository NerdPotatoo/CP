#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    ll val;
    vector<ll> v;
    for(ll i = 0; i<n; i++) {

        cin >> val;
        v.push_back(val);
    }
    ll x,y,z;
    cin >> x; 
    v.erase(v.begin()+(x-1));
    cin >> y >> z;
    v.erase(v.begin()+(y-1) , v.begin()+(z-1));

    cout << v.size() << '\n';
    for(ll i = 0;i<v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}