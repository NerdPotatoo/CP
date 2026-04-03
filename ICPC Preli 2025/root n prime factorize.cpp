#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

/// complexity O(sqrt(n) log(n))
vector<ll> primeFactorize(ll n){
    vector<ll>factors;
    if(n==1){
        return factors;
    }
    for(ll i=2; i*i<=n; i++){
        if(n%i==0){
            while(n%i==0){
                n /= i;
                factors.push_back(i);
            }
        }
    }
    if(n!=1){
        factors.push_back(n);
    }
    return factors;
}

int main(){
    ll n = 120*6;
    vector<ll>v = primeFactorize(n);
    for(ll p : v){
        cout<<p<<endl;
    }
    return 0;
}
