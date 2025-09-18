#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pii>
#define vvi vector<vector<int>>
#define ll long long
#define vl vector<ll>
#define rep(i,a,b) for(ll i=a;i<b;i++)

vector<bool> isPrime(1e7, true);

void initPrime(vector<bool>& isPrime){
    ll NMAX=1e7;
    isPrime[0]=isPrime[1]=false;
    for(ll i=2LL; i*i<NMAX;i++){
        if (isPrime[i]){
            for (ll j=i*i; j<NMAX; j+=i){
                isPrime[j]=false;
            }
        }
    }
}

void parcoursArbre(set<int>& vus, vector<bool> pris, string s, int cur){
    rep(i,0,s.length()){
        if (!pris[i]){
            pris[i]=true;
            if (isPrime[10*cur+(s[i]-'0')])
            vus.insert(10*cur+(s[i]-'0'));
            parcoursArbre(vus,pris,s,10*cur+(s[i]-'0'));
            pris[i]=false;
        }
    }
}

void solve(){
    set<int> vus;
    string s;
    cin>>s;
    vector<bool> pris(s.length(), false);
    int cur=0;
    parcoursArbre(vus, pris, s, cur);
    cout<<vus.size()<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    initPrime(isPrime);
    rep(i,0,t)
    solve();
}

