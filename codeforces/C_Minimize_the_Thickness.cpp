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
    int mini=n;
    rep(i,0,n){
        bool ok=true;
        ll targetS=0;
        int minTaille=i+1;
        rep(j,0,i+1){
            targetS+=tab[j];
        }
        int j=i+1;
        while (j<n){
            int curS=0;
            int curL=0;
            while (j<n && curS+tab[j]<=targetS){
                curS+=tab[j];
                curL++;
                j++;
            }
            if (j==n && curS<targetS) ok=false;
            if (j<n && curS<targetS && curS+tab[j]>targetS){
                ok=false;
                break;
            }
            minTaille=max(minTaille,curL);  
        }
        if (ok){
            mini=min(mini,minTaille);
        }
    }
    cout<<mini<<"\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin>>t; rep(i,0,t)
    solve();
}