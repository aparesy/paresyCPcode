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
        ll k;
        cin>>k;
        vl a(n);
        for (auto& x : a) cin>>x;
        vl b(n);
        for (auto& x : b) cin>>x;
        vector<pair<ll, int>> tab;
        for (int i=0;i<n;i++){
            tab.push_back({a[i]+b[i],i});
            sort(tab.begin(), tab.end());
        }
        ll tot=0LL;
        for (int i=0;i<n;i++){
            tot+=abs(a[i]-b[i]);
        }
        ll mini=__INT64_MAX__;
        int id_min=0;
        for (int i=0;i<n-1;i++){
            if (tab[i+1].first-tab[i].first<mini){
                mini=tab[i+1].first-tab[i].first;
                id_min=i;
            }
        }
        int j1=tab[id_min].second;
        int j2=tab[id_min+1].second;
        if (max(a[j1], b[j1]) < min(b[j2], a[j2])){
            tot-=2LL*(max(a[j1], b[j1]) - min(b[j2], a[j2]));
        }
        cout<<tot<<endl;
    }
}