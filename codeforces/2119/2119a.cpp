#include <bits/stdc++.h>

#include <algorithm>
using namespace std;
#define ll long long


void solve(){
    int n;
    cin>>n;
    ll px,py,qx,qy;
    cin>>px>>py>>qx>>qy;
    vector<ll> v(n);
    for (auto& x : v) cin>>x;
    ll tot = std::reduce(v.begin(), v.end());
    ll mini = max(0LL,2*(*max_element(v.begin(), v.end())) - tot);
    if ((qx-px)*(qx-px) + (qy-py)*(qy-py) > tot*tot || (qx-px)*(qx-px) + (qy-py)*(qy-py) < mini*mini)
    cout<<"No\n";
    else cout<<"Yes\n";
    return;
}

int main(){
    int t;
    cin>>t;
    while (t--){
        solve();
        
    }
}