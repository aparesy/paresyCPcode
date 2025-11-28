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

    ll aaaa=tab[0];
    rep(i,0,n){
        aaaa=max(tab[i],aaaa);
        if (i%2){
            tab[i]=max(tab[i],aaaa);
        }
    }

    ll prefmax=tab[0];
    ll tot=0;
    rep(i,0,n-1){
        if (i%2){
            tab[i]=max(prefmax,tab[i]);
            if (tab[i]<=tab[i+1]){
                tot+=tab[i+1]-tab[i]+1;
                tab[i+1]-=tot;
            }
        }
        else{
            if (tab[i]>=tab[i+1]){
                tab[i+1]=max(tab[i+1],prefmax);
                if (tab[i]>=tab[i+1]){
                    tot++;
                    tab[i+1]=tab[i];
                    tab[i]--;
                }
            }
        }
        prefmax=max(prefmax,tab[i]);
    }
    cout<<tot<<"\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin>>t; rep(i,0,t)
    solve();
}