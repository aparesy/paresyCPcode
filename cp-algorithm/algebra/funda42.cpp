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

void remonteEuclide(ll a, ll b, ll& x, ll& y){
    int x1 = 0, y1 = 1, a1 = a, b1 = b;
    while (b1) {
        int q = a1 / b1;
        tie(x, x1) = make_tuple(x1, x - q * x1);
        tie(y, y1) = make_tuple(y1, y - q * y1);
        tie(a1, b1) = make_tuple(b1, a1 - q * b1);
    }
}

void solve(){
    ll a,b,c;
    cin>>a>>b>>c;
    ll x1,x2; cin>>x1>>x2;
    ll y1,y2; cin>>y1>>y2;
    if (a==0 && b==0){
        if (c!=0){
            cout<<0; return;
        }
        else{
            cout<<(x2-x1+1LL)*(y2-y1+1LL); return;
        }
    }

    if (c%gcd(a,b)){
        cout<<0; return;
    }

    ll x0,y0;
    x0=y0=1LL;
    remonteEuclide(a,b,x0,y0); 
    x0*=(c/gcd(a,b));
    y0*=(c/gcd(a,b));

    x0-=x1;
    ll q = x0/(b/gcd(a,b));
    x0-=q*(b/gcd(a,b));
    x1+=q*(a/gcd(a,b));
    if (x0<0LL){
        
    }
    x0+=x1;
    if (x1>x2){
        cout<<0; return;
    }
}   

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}