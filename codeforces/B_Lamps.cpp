// Useful functions : nth_element, rotate, unique, merge, count, generate

#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define pdd pair<double,double>
#define vi vector<int>
#define vii vector<pii>
#define vvi vector<vector<int>>
using ll=long long;
#define vl vector<ll>
#define vvl vector<vector<ll>>
#define vb vector<bool>
#define F first 
#define S second
#define rep(i,a,b) for(int i=a;i<b;i++)
#define input(tab) for (auto& x : tab)cin>>x
#define all(x) x.begin(),x.end()

ll get(){
   ll x;
   cin>>x;
   return x;
}


void solve(){
    int n=get();
    ll tot=0;
    vector<pair<pair<ll,ll>,int>> lamps(n);
    rep(i,0,n){
        cin>>lamps[i].first.first>>lamps[i].first.second;
        lamps[i].second=i;
    }
    map<ll,int> takenPerStep;
    sort(all(lamps), [](const pair<pair<ll,ll>,int>& a, const pair<pair<ll,ll>,int>& b){if (a.first.first==b.first.first) 
        return a.first.second>b.first.second; else return a.first.first<b.first.first;});
    rep(i,0,n){
        if (lamps[i].first.first>takenPerStep[lamps[i].first.first]){
            takenPerStep[lamps[i].first.first]++;
            tot+=lamps[i].first.second;
        }
    }
    cout<<tot<<"\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin>>t; rep(i,0,t)
    solve();
}