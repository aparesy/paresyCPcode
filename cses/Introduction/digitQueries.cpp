#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define pdd pair<double,double>
#define vi vector<int>
#define vii vector<pii>
#define vvi vector<vector<int>>
#define ll unsigned long long
#define vl vector<ll>
#define vvl vector<vector<ll>>
#define vb vector<bool>
#define F first 
#define S second
#define rep(i,a,b) for(int i=a;i<b;i++)
#define input(tab) for (auto& x : tab)cin>>x

ll nDigit(ll target, ll i){
    rep(j,0,i){
        target/=10LL;
    }
    return target%10LL;
}

void solve(){
    ll k;
    cin>>k;
    ll curPow=0LL;
    while (k>9LL*((ll)pow(10LL,curPow))*(curPow+1LL)){
        k-=9LL*((ll)pow(10LL,curPow))*(curPow+1LL);
        curPow+=1LL;
    }
    cout<<nDigit((k+curPow)/(curPow+1LL)+(ll)pow(10LL,curPow)-1LL, curPow-((k-1LL)%(curPow+1LL)))<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int q;
    cin>>q;
    rep(i,0,q)
    solve();
}