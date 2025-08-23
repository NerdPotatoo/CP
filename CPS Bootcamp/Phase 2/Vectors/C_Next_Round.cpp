#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);

    for(auto &e:a) cin >> e;
    int m = a[k-1], cnt = 0;
    for(int i = 0; i<n; i++)
    {
        if(a[i] >= m && a[i]>0) cnt++;
    }
    cout << cnt << '\n';
}