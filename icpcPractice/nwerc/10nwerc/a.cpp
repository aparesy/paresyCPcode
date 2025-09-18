#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define pdd pair<double,double>
#define vi vector<int>
#define vii vector<pii>
#define vvi vector<vector<int>>
#define ll long long
#define vl vector<ll>
#define rep(i,a,b) for(int i=a;i<b;i++)

void solve(){
    ll p,n;
    cin>>p>>n;
    vii tab(n);
    rep(i,0,n){
        int x;
        cin>>x;
        tab[i]={x,i};
    }
    ll sum=accumulate(tab.begin(), tab.end(), 0LL, [](ll acc, const std::pair<int,int>& p){return acc+p.first;});
    sort(tab.begin(),tab.end(), [](auto& a,auto& b){if (a.first==b.first) return a.second<b.second; return a.first>b.first;});
    if (p>sum){
        cout<<"IMPOSSIBLE\n";
        return;
    }
    ll reste=sum-p;
    int derniereColonne=0;
    while(reste>0&&derniereColonne<n-1&&reste>=(derniereColonne+1)*(tab[0].first-tab[derniereColonne+1].first)){
        rep(i,0,derniereColonne+1){
            reste-=(tab[i].first-tab[derniereColonne+1].first);
            tab[i].first=tab[derniereColonne+1].first;
        }
        derniereColonne++;
    }
    if (reste>0){
        rep(i,0,derniereColonne+1){
            tab[i].first-=(reste/(derniereColonne+1))+(i>=((-reste)%(derniereColonne+1)+(derniereColonne+1)));
        }
    }
    sort(tab.begin(), tab.end(), [](auto a, auto b){return a.second<b.second;});
    rep(i,0,n) cout<<tab[i].first<<" ";
    cout<<endl;
}   

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    rep(i,0,t)
    solve();
}   