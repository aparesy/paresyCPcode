#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>

const int NMAX=1e6;
vector<bool> isPrime(NMAX+1, true);

void sieve(int n){
    isPrime[0]=false;
    isPrime[1]=false;
    for (int i=2; i*i<= n; i++){
        if (isPrime[i]){
            for (int j=i*i; j<=n; j++){
                isPrime[j]=false;
            }
        }
    }
}

vector<bool> isSuperPrime = isPrime;

for (int i=0; i<=NMAX; i++){
    if (isPrime[i]){
        
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        
        
    }
}