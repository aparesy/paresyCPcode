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
    ll n,m;
    cin>>n>>m;
    vl tab(n);
    input(tab);
    vector<pair<ll,ll>> bAndC(m);
    rep(i,0,m){
        cin>>bAndC[i].first;
    }
    rep(i,0,m){
        cin>>bAndC[i].second;
    }
    sort(all(bAndC));
    int skipped=0;
    int tot=0;
    priority_queue<ll, vl, greater<ll>> swords;
    rep(i,0,n){
        swords.push(tab[i]);
    }
    int i=0;
    while(!swords.empty()){
        if (i==m) break;
        ll s=swords.top();
        if (bAndC[i].first>s){
            // Do nothing
            if (skipped){
                skipped--;
                tot++;
            }
            swords.pop();
        }
        else{
            if (bAndC[i].second==0){
                skipped++;
                i++;
            }
            else{
                swords.pop();
                swords.push(max(s, bAndC[i].second));
                tot++;
                i++;
            }
        }
    }
    tot+=min((int) swords.size(), skipped);
    cout<<tot<<"\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin>>t; rep(i,0,t)
    solve();
}