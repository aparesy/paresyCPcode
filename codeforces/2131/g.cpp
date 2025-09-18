#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define pdd pair<double,double>
#define vi vector<int>
#define vii vector<pii>
#define vvi vector<vector<int>>
#define ll long long
#define vl vector<ll>
#define rep(i,a,b) for(int i=a;i<b;i++)

vector<ll> fact;
 
void computeFact(ll mod){
    fact.push_back(1);
    ll cur=1;
    while(cur<50){
        ll tmp=1LL;
        for (auto x : fact){
            tmp*=x;
            tmp=tmp%mod;
        }
        fact.push_back(tmp*cur);
        fact[cur]=fact[cur]%mod;
        cur++;
    }
}

void solve(){
    ll mod = 1e9+7;
    ll n,k;
    cin>>n>>k;
    deque<ll> tab;
    ll tmp;
    rep(i,0,n){
        cin>>tmp;
        tab.push_back(tmp);
    }
    ll tot=1LL;
    sort(tab.begin(), tab.end());
    while (k>0LL){
        ll cur=tab.front();
        if (tab.front()<fact.size() && ((1LL<<(cur-1))<=k)){
            k-=(1LL<<(cur-1));
            tot*=fact[cur];
            tot%=mod;
            if (tot<0LL) tot+=mod;
            tab.pop_front();
        }
        else{
            tab.pop_front();
            k-=1LL;
            tot*=cur;
            tot%=mod;
            if (tot<0LL) tot+=mod;
            for (int i=min((int)fact.size()*2, (int)cur)-1;i>=1; i--){
                tab.push_front(i);
            }
        }
     //   cout<<tot<<" ";
    }
    cout<<tot<<endl;
}

int main(){
    ll mod = 1e9+7;
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    computeFact(mod);
 //   for (auto x : fact) cout<<x<<" "<<flush;
    rep(i,0,t)
    solve();
 //   cout<<fact[3]<<endl;
}