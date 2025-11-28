#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define pdd pair<double,double>
#define vi vector<int>
#define vii vector<pii>
#define vvi vector<vector<int>>
#define ll long long
#define vl vector<ll>
#define vvl vector<vector<ll>>
#define vb vector<bool>
#define F first 
#define S second
#define rep(i,a,b) for(int i=a;i<b;i++)
#define input(tab) for (auto& x : tab)cin>>x

void solve(){
    int n;
    cin>>n;
    vl tab(n);
    input(tab);
    sort(tab.begin(),tab.end(),greater<int>());
    ll scoreA=0LL;
    ll scoreB=0LL;
    vector<pair<ll,ll>> occ;
    int i=0;
    while(i<n){
        if (tab[i]%2){
            int i2=i;
            while(i2<n && tab[i2]==tab[i])i2++;
            occ.push_back({i2-i,tab[i]});
            i=i2-1;
        }
        else{
            scoreA+=tab[i]/2LL;
            scoreB+=tab[i]/2LL;
        }
        i++;
    }
    int joueurCur=0;
    sort(occ.begin(),occ.end(),greater<pair<ll,ll>>());
    for (auto [nbOcc, val] : occ){
            if (joueurCur){
                scoreB+=(val+1LL)/2LL*nbOcc;
                scoreA+=(val)/2LL*nbOcc;
            }
            else{
                scoreB+=(val)/2LL*nbOcc;
                scoreA+=(val+1LL)/2LL*nbOcc;
            }
            joueurCur=1-joueurCur;
    }
    cout<<scoreA<<" "<<scoreB<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    rep(i,0,t)
    solve();
}