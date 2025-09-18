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

vector<ll> fibo;

void computeFib(){
    ll a=0;
    ll b=1;
    while (b<1e17){
        fibo.push_back(b);
        ll tmp=a;
        a=b;
        b+=tmp;
    }
}

void solve(){
    ll n;
    cin>>n;
    ll tot=0LL;
    for (int i=0;fibo[i]<=n&&i<fibo.size();i+=3){
        tot+=fibo[i];
    }
    cout<<tot<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    fibo.push_back(0);
    computeFib();
    int t;
    cin>>t;
    rep(i,0,t)
    solve();
}