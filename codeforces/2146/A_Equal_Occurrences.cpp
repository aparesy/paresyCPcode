#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define pdd pair<double,double>
#define vi vector<int>
#define vii vector<pii>
#define vvi vector<vector<int>>
#define ll long long
#define vl vector<ll>
#define vvl vector<vector<ll>>
#define vb vector<bool>
#define F first 
#define S second
#define rep(i,a,b) for(int i=a;i<b;i++)
#define input(tab) for (auto& x : tab)cin>>x

void solve(){
    int n;
    cin>>n;
    vl tab(n);
    input(tab);
    int i=0;
    vector<pair<int,ll>> occurences;
    while (i<n){
        int i2=i;
        while (i2<n && tab[i2]==tab[i]){
            i2++;
        }
        occurences.push_back({i2-i,tab[i]});
        i=i2;
    }
    ll maxi=0LL;
    ll tot=0LL;
    ll lastVal=1LL;
    sort(occurences.begin(),occurences.end());
    for (int j=occurences.size()-1;j>=0;j--){
        auto [occ, val]=occurences[j];
        tot/=lastVal;
        tot+=1;
        tot*=(ll)occ;
        lastVal=occ;
        if (tot>maxi) maxi=tot;
    }
    cout<<maxi<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;cin>>t;
    rep(i,0,t)
    solve();
}