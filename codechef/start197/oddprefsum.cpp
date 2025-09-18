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
        ll tot=0;
        for (int i=0;i<n;i++){
            if (tab[i]&1){
                tot++;
            }
        }
        if (tot==1)cout<<"YES\n"; else cout<<"NO\n";
    }
}