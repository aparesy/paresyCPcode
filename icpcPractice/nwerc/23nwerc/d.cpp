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
    int n=7;
    vector<string> agenda(n);
    rep(i,0,n){
        cin>>agenda[i];
    }
    int m=24;
    int d=get();
    int h=get();

    double maxi=0;
    vi curDays(n);
    rep(i,0,d){
        curDays[n-1-i]=1;
    }
    do{
        vii hoursTot(24);
        rep(i,0,m) hoursTot[i].second=i;
        rep(i,0,n){
            if (curDays[i]){
                rep(j,0,m){
                    if (agenda[i][j]=='.') hoursTot[j].first++;
                }
            }
        }
        sort(all(hoursTot),greater<pii>());
        double tot=0;
        rep(i,0,h){
            tot+=hoursTot[i].first;
        }
        tot/=((double) h);
        tot/= ((double) d);
        maxi=max(maxi,tot);
    }
    while(next_permutation(all(curDays)));
    cout<<fixed<<setprecision(7)<<maxi;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}