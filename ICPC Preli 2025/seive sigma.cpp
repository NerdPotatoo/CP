#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

const int nmax = 110;

int sigma[nmax];

/// complexity o(n log n)
void seive_sigma(){
    for(int i=1; i<=nmax; i++){
        for(int m=i; m<=nmax; m+=i){
            sigma[m] += i;
        }
    }
}

int main(){
    seive_sigma();
    cout<<sigma[10]<<endl;
}

