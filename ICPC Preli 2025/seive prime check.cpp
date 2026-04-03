#include <bits/stdc++.h>
using namespace std;
typedef long long int li;
 
const int nmax = 1e7;
bool mark[nmax+5];

/// complexity O(n log log n)
void seive(){
    mark[0] = mark[1] = true;
    for(int i=2; i<=nmax; i++){
        if(!mark[i]){
            for(int m = 2*i; m<=nmax; m+=i){
                mark[m] = true;
            }
        }
    }
}

int main(){
    seive();
    for(int i=1; i<=20; i++){
        if(!mark[i]) cout<<i<<endl;
    }
    return 0;
}
/// number of prime upto n = n/log n
