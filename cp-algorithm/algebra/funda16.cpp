#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>

ll gcd(ll a, ll b, ll& x1, ll& y1){
    // x1*a + y1*b = a1
    // x2*a + y2*b = b1
    ll x2=0LL;
    ll y2=1LL;
    ll a1=a;
    ll b1=b;
    ll q;
    while(b1){
        // a1 = b1, b1 = a1%b1, x1=x2, y1=y2, x2=x1-q*x2, idem
        q=a1/b1;
        tie(x1,x2)=make_tuple(x2, x1-q*x2);
        tie(y1,y2)=make_tuple(y2, y1-q*y2);
        tie(a1,b1)=make_tuple(b1, a1-q*b1); 
    }
//    cout<<x1<<" "<<y1<<endl;
    return a1;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    int t0=t;
    cin>>t;
    while(t--){
        cout<<"Case "<<t0-t+1<<": ";
        ll p,a,b,c;
        cin>>a>>b>>c>>p;
        ll x1,y1; x1=y1=0;
        ll d1=gcd(a,b);
        ll d2=gcd(d2, c, x1, y1);
        if (p%d2){
            cout<<0<<endl;
        }
        else{
            ll tot=0;
            for (ll nbC=0; p-nbC*c>=0; nbC+=d1){
                ll x2,y2;
                x2=y2=0;
                
            }
        }
    }
}