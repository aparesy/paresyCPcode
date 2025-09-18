#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        ll a,b;
        cin>>a>>b;
        if (b%a) cout<<a*b/gcd(a,b)<<endl;
        else cout<<b*b/a<<endl;
    }
}

