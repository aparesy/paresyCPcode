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
        ll n;
        cin>>n;
        vl tab(n);
        for (auto& x : tab) cin>>x;
        bool ok=true;
        int prec=-1;
        for (auto x : tab){
            if (x==0){
                ok=false;
            }
            if (x!=-1){
                if (prec!=-1){
                    if (x!=prec) ok=false;
                }
                prec=x;
            }
        }
        if (ok) cout<<"YES"; else cout<<"NO";
        cout<<"\n";
    }
}