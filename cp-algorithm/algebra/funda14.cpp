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
        tie(x1,x2) = make_tuple(x2, x1-q*x2);
        tie(y1,y2)=make_tuple(y2, y1-q*y2);
        tie(a1,b1)=make_tuple(b1, a1-q*b1); 
    }
    return a1;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll a,b;
    while (cin>>a>>b) {
        ll x1=1LL; ll y1=0LL;
        ll res=gcd(a,b,x1,y1);
        cout<<x1<<" "<<y1<<" "<<res<<endl;
    }
}