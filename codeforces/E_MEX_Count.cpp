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
    sort(all(tab));
    bool ok=true;
    if (tab[0]) ok=false;
    int maxConsecutive=0;
    rep(i,1,n){
        if (ok && tab[i]>tab[i-1]){
            if (tab[i]==tab[i-1]+1){
                maxConsecutive++;
            }
            else{
                ok=false;
            }
        }
    }
    // Si on retire qqes éléments (reste), les valeurs atteignables sont 0
    vii occ(maxConsecutive+1);
    rep(i,0,maxConsecutive+1){
        occ[i].second=i;
    }
    rep(i,0,n){
        if (tab[i]<=maxConsecutive){
            occ[tab[i]].first++;
        }
    } 
    sort(all(occ));
    int j=0;
    vi res(n);
    rep(i,1,n+1){
        while (j<n && occ[j].first<=i){
            j++;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin>>t; rep(i,0,t)
    solve();
}