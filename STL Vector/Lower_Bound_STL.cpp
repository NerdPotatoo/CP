#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i  = 0; i<n; i++) cin >> v[i];
    int q; cin >> q;
    while(q--)
    {
        int x;
        cin >> x;
        auto it = lower_bound(v.begin(), v.end(), x) - v.begin();

        if(it == n){
            cout << "No " << n+1 << '\n'; 
        } 
        else{
            if(v[it] == x)
            {
                cout << "Yes ";
            }
            else cout << "No ";

            cout << it + 1 << '\n';
        }


    }
}