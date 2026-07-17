// Useful functions : nth_element, rotate, unique, merge, count, generate

#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define pdd pair<double,double>
#define vi vector<int>
#define vii vector<pii>
#define vvi vector<vector<int>>
using ll=unsigned long long;
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

ll inf=1E18;

void solve(){
    ll n=get(); ll k=get();
    vl tab(n);
    input(tab);
    ll sum=accumulate(all(tab), 0ll);
    ll maxi=*max_element(all(tab));
    for (int i=n; i>=1; i--){
        bool possible=true;
        ll maxCard=sum;
        maxCard+=k;
        maxCard=maxCard/i*i;
        if (maxCard < sum) possible=false;
        ll nbDeck=maxCard/i;
        if (maxi>nbDeck) possible=false;
        if (possible){
            cout<<i<<"\n";
            return;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin>>t; rep(i,0,t)
    solve();
}