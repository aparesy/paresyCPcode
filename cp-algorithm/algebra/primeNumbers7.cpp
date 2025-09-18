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

const ll maxi=1e10+1LL;
const ll racine=sqrt(maxi)+1LL;
vi prime(racine,1);
set<pii> primeCount;

void initPrime(){
    for( int i=2;i*i<racine;i++){
        if(prime[i]){
            for(int j=i*i;j<racine;j+=i){
                prime[j]=false;
            }
        }
    }
    int counte=1;
    primeCount.insert({2,1});
    for (int i=3;i<racine;i+=2){
        if (prime[i]){
            counte++;
            primeCount.insert({i,counte});
        }
    }
}

void solve(){
    ll n,k;cin>>n>>k;

    int target=sqrt(n);
    int a=(primeCount.upper_bound({target,INT_MAX}))->second;
    cout<<a<<" ";
    if (k>n){
        cout<<0<<"\n";
        return;
    }
    int b=(primeCount.upper_bound({sqrt(k),INT_MAX}))->second;
    cout<<a-b<<"\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    initPrime();
    int t;cin>>t;rep(i,0,t)
    solve();
}