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
    ll n,k;
    cin>>n>>k;
    vector<pair<pii,ll>> cas(n);
    set<ll> real;
    map<ll,ll> highest;
    map<ll,vector<pii>> valToInter;
    rep(i,0,n){
        cin>>cas[i].first.first>>cas[i].first.second>>cas[i].second;
        real.insert(cas[i].second);
        valToInter[cas[i].second].push_back(cas[i].first); // todo : support multiple
    }
//    sort(all(cas));
    while(real.size()){
        ll tmp=*(real.rbegin());
        real.erase(*(real.rbegin()));
        queue<ll> q;
        highest[tmp]=tmp;   
        q.push(tmp);
        while(!q.empty()){
            ll s=q.front();
            q.pop();
            for (auto [li,ri] : valToInter[s]){
                auto it=real.lower_bound(li);
                while(it!=real.end() && (*it)<=ri){
                    highest[*it]=tmp;
                    q.push(*it);
                    it=real.erase(it);                
                }
            }
        }
    }

    ll maxi=k;
    for (auto [inter,val] : cas){
        if (inter.first<=k&&inter.second>=k){
            maxi=max(maxi,highest[val]);
        }
    }
    cout<<maxi<<"\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin>>t; rep(i,0,t)
    solve();
}