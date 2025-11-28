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
    //n² is okay. For each two, do a binary search  
    ll n,x;
    cin>>n>>x;
    vector<pair<ll,int>> tab(n);
    rep(i,0,n){
        cin>>tab[i].first;
        tab[i].second=i;
    }
    sort(all(tab));
    rep(i,0,n){
        rep(j,i+1,n-1){
            ll target=x-tab[i].first-tab[j].first;
            int l=j+1;
            int r=n;
            while (r-l>1){
                int m=(r+l)/2LL;
                if (tab[m].first>target){
                    r=m;
                }
                else l=m;
            }
            if (tab[l].first==target){
                cout<<tab[i].second+1<<" "<<tab[j].second+1<<" "<<tab[l].second+1;
                return;
            }
        }
    }
    cout<<"IMPOSSIBLE";
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}