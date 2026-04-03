#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

/// taw(n) = total divisors of n
vector<ll>divisors;

/// complexity o(sqrt(n))
ll taw(ll n){
    ll counter = 0;
    for(ll i=1; i*i<=n; i++){
        if(n%i==0){
            if(n/i==i){
                counter++;
                divisors.push_back(i);
            }
            else{
                counter+=2;
                divisors.push_back(i);
                divisors.push_back(n/i);
            }
        }
    }
    sort(divisors.begin(), divisors.end());
    return counter;
}
int main(){
    cout<<taw(72)<<endl;
    for(int x:divisors) cout<<x<<" ";
    return 0;
}
