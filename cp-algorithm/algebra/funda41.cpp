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

ll gcd(ll a, ll b){
    if (b==0) return a;
    return gcd(b, a%b);
}

void solve(){
    ll a,b,c;
    cin>>a>>b>>c;
    if (c==0){
        cout<<"Yes\n";return;
    }
    if (a==0 && b==0){
        cout<<"No\n"; return;
    }
    if (c%gcd(a,b)==0){
        cout<<"Yes\n";
        return;
    }
    cout<<"No\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    
    cin.tie(0);
    rep(i,0,t){ cout<<"Case "<<i+1<<": ";
    solve();
    }
}