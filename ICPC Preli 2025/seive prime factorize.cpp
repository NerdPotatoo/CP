#include <bits/stdc++.h>
using namespace std;
typedef long long int li;

const int nmax = 1e7;
int mark[nmax+5];

/// complexity O(n log log n)
void seive(){
    mark[0] = mark[1] = 0;
    for(int i=2; i<=nmax; i++){
        if(!mark[i]>0){
            for(int m = 2*i; m<=nmax; m+=i){
                mark[m] = i;
            }
        }
    }
}

/// complexity O(log n)
vector<int> factorize(int n){
    vector<int>factors;
    if(n==1) return factors;

    while(mark[n] != 0){
        factors.push_back(mark[n]);
        n /= mark[n];
    }

    factors.push_back(n);

    return factors;
}

int main(){
    seive();
    int n = 360;
    vector<int>v = factorize(n);
    for(int x : v) cout<<x<<endl;
    return 0;
}
/// number of prime upto n = n/log n
