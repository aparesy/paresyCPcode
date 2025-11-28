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
    string s;
    cin>>s;
    map<int,set<string>> cnt;
    rep(i,0,n-k+1){
        string t=s.substr(i,k);
        int tot=0;
        rep(j,0,n-k+1){
            if (t.compare(s.substr(j,k))==0){
                tot++;
            }
        }
        if (cnt[tot].size()==0) cnt[tot]=set<string>();
        if ((find(all(cnt[tot]),t))==cnt[tot].end()) cnt[tot].insert(t);
    }
    auto it=cnt.rbegin();
    while ((*it).second.size()==0) it--;
    cout<<((*cnt.rbegin()).first)<<"\n";
    for (auto jk : ((*cnt.rbegin()).second)){
        cout<<jk<<" ";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}