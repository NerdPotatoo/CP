#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;cin >> n;
    vector<int> a(n);
    for(auto &e:a) cin >> e;
    // sort(a.rbegin(), a.rend());
    int s = 0 , d = 0, i = 0, j= n-1, ok = 1;
    while(i<=j)
    {
        if(ok)
        {
            if(a[i] > a[j]) s += a[i++]; 
            else  s += a[j--]; 
        }
        else{
            if(a[i] > a[j]) d += a[i++]; 
            else  d += a[j--];
        }
        ok ^= 1;
    }
    cout << s << " " << d << endl;
}