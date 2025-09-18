#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    vl tab(n);
    for (auto& x : tab) cin>>x;
    unordered_map<ll,int> h;
    ll tot=0;
    for (int i=0;i<n;i++){
        tot+=h[i-tab[i]];
        h[i+tab[i]]++;
    }
    cout<<tot;
}