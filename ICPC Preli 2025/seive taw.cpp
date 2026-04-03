#include <bits/stdc++.h>
using namespace std;

const int nmax = 100;
int taw[nmax+10];
vector<int> divisors[nmax+10] ;

/// complexity o(n lon(n))
void seiveTaw(){
    for(int i=1; i<=nmax; i++){
        for(int m=i; m<=nmax; m+=i){
            taw[m]++; 
            divisors[m].push_back(i);
        }
    }
}

int main(){
    seiveTaw();
    for(int i=1; i<=25; i++){
        cout<<i<<": "<<taw[i]<<endl;
        for(int x:divisors[i]){
            cout<<x<<" ";
        }
        cout<<endl;
    }
    return 0;
}
