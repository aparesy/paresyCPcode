#include <bits/stdc++.h>

using namespace std;

#define int long long 

signed main(){
    int t;
    cin>>t;
    for (int i=0;i<t;i++){
        int x,y;
        cin>>x>>y;
        if (y>2ll*x) cout<<"YES\n";
        else cout<<"NO\n";
    }
}