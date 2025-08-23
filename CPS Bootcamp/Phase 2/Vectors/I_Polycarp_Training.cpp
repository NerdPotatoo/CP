#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &e:a) cin >> e;
    sort(a.begin(),a.end());
    int m = 0;
    for(int i = 0; i<n; i++)
    {
        if(m<a[i]){
            m++;
        }
    }
    cout << m << '\n';
}