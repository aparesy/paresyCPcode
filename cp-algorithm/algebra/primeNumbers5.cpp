#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define pdd pair<double,double>
#define vi vector<int>
#define vii vector<pii>
#define vvi vector<vector<int>>
#define ll long long
#define vl vector<ll>
#define vvl vector<vector<ll>>
#define rep(i,a,b) for(int i=a;i<b;i++)

void solve(){
    int n;
    cin>>n;
    vector<int> isPrime(n+1,-1);
    isPrime[0]=1;
    isPrime[1]=1;
    for (int i=2;i<n;i++){
        if (isPrime[i]==-1){
            for (int j=i*i;j<=n;j+=i){
                if (isPrime[j]==-1) isPrime[j]=i;
            }
        }
    }
    vi primes;
    rep(i,0,n+1){
        if (isPrime[i]==-1){
            primes.push_back(i);
        }
    }
    int m=primes.size();
    int tot=0;
    rep(i,0,m){
        rep(j,i+1,m){
            int a=1;
            int b=1;
            while(pow(primes[i],a)*primes[j]<=n){
                while(pow(primes[i],a)*pow(primes[j],b)<=n){
                    tot++;
                    b++;
                }
                b=1;
                a++;
            }
        }
    }
    cout<<tot<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}