#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

/// complexity O(sqrt n)
ll sigma(ll n){
    ll result = 0;
    for(int i=1; i*i<=n; i++){
        if(n%i == 0){
            if(i == n/i){
                result += i;
            }
            else{
                result += i;
                result += n/i;
            }
        }
    }
    return result;
}

int main(){
    int x = 1e9+7;
    cout<<sigma(x)<<endl;
    return 0;
}
