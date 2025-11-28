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
    ll mini=(*(min_element(all(tab))));
    int ind=0;
    for (int i=n-1;i>=1;i--){
        if (tab[i]<tab[i-1]){
            ind=i;
            break;
        }
    }
    if (ind==0){
        cout<<0<<"\n";
        return;
    }
    rep(j,0,ind){
        if (tab[j]==mini){
            cout<<-1<<"\n";
            return;
        }
    }
    cout<<ind<<"\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=get();
    rep(i,0,t)
    solve();
}