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
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define input(tab) for (auto& x : tab)cin>>x
#define all(x) x.begin(),x.end()

ll get(){
   ll x;
   cin>>x;
   return x;
}

struct parts{
    ll w; ll h; ll b;
};

const ll deux=2;

const int NMAX=500001;
ll bestGain[NMAX];

void solve(){
    int n=get();
    vector<parts> tab(n);
    rep(i,0,n){
        cin>>tab[i].w>>tab[i].h>>tab[i].b;
    }
    ll Weight=0;
    ll happiness=0;
    rep(i,0,n){
        Weight+=tab[i].w;
        happiness+=tab[i].b;
    }
    rep(i,0,NMAX){
        bestGain[i]=0;
    }
    rep(i,0,n){
        for (ll j=NMAX-1; j>=tab[i].w*deux; j--){
            bestGain[j]=max(bestGain[j], bestGain[j-tab[i].w*deux]+(tab[i].h-tab[i].b));
        }
    }
    ll maxi=0;
    rep(i,0,NMAX){
        if (i<=Weight){
            maxi=max(maxi, bestGain[i]);
        }
    }
    cout<<happiness+maxi<<"\n";
    // vector<pair<ll,ll>> dp(n);
    // if (tab[0].w*deux<=Weight && tab[0].h>tab[0].b){
    //     dp[0].first=tab[0].w*deux;
    //     dp[0].second=tab[0].h-tab[0].b;
    // }
    // rep(i,1,n){
    //     dp[i].first=dp[i-1].first;
    //     dp[i].second=dp[i-1].second;
    //     ll curGain=tab[i].h-tab[i].b;
    //     ll curCost=tab[i].w*deux;
    //     rep(j,0,i){
    //         if (dp[j].first+curCost<=Weight && dp[j].second+curGain>dp[i].second){
    //             dp[i].second=dp[j].second+curGain;
    //             dp[i].first=dp[j].first+curCost;
    //         }
    //     }
    //     if (curCost<=Weight && curGain>dp[i].second){
    //         dp[i].first=curCost;
    //         dp[i].second=curGain;
    //     }
    // }
    // cout<<happiness+dp[n-1].second<<"\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}