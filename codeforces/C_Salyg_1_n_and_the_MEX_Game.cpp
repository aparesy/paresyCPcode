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
    vl tab(n);
    input(tab);
    set<ll> s;
    rep(i,0,n){
        s.insert(tab[i]);
    }
    ll tmp=(*s.lower_bound(0));
    ll lowestMissing=99999999999ll;
    if (tmp==0){
        while(s.count(tmp)) tmp++;
    }
    else tmp=0;
    lowestMissing=tmp;
    while(lowestMissing>=0){
        cout<<lowestMissing<<endl;
        s.insert(lowestMissing);
        cin>>tmp;
        s.erase(tmp);
        lowestMissing=tmp;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin>>t; rep(i,0,t)
    solve();
}