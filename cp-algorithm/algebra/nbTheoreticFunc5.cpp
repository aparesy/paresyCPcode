#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>

const int NMAX=3*1e9;

void computePrime(vector<int>& primeDivisor, int NMAX){
    primeDivisor[0] = primeDivisor[1]= 1;
    for (int i=2; i*i<= NMAX; i++){
        if (primeDivisor[i]==-1){
            for (int j=i*i; j<= NMAX; j+=i){
                if (primeDivisor[j]==-1){
                    primeDivisor[j]=i;
                }
            }
        }
    }
    // for (int i=0;i<=100;i++){
    //     cout<<primeDivisor[NMAX-i]<<" ";
    // }
}


void decomposition(int n, vector<pair<int,int>>& facteurs){
    if (n<=1) return;
    for (int i=2;i*i<=n;i++){
        if (n%i==0){
            int a=1;
            while(n%(int)pow(i,a)==0)a++;
            facteurs.push_back({i,a-1});
            return decomposition(n/(int)(pow(i,a-1)+0.001), facteurs);
        }
    }
    facteurs.push_back({n,1});
}

ll inversePhi(ll k){

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll k;
    cin>>k;
    cout<<inversePhi(k)<<endl;
}