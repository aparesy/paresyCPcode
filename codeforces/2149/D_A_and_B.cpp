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

ll solve2(string s){
    int n=s.length();
    ll maxi=999999999999;
    int tota=0;
    rep(i,0,n){
        if (s[i]=='a')tota++;
    }
    vector<pair<int,int>> characs;
    int curA=0;
    rep(i,0,n){
        if (s[i]=='a'){ characs.push_back({i,curA});
            curA++;
        }
    }
    ll tot=0;
    for (auto [pos,nb] : characs){
        tot+=pos-nb;
    }
    maxi=min(maxi,tot);
    for (int i=characs.size()-1;i>=0;i--){
        auto [pos,nb] = characs[i];
        tot-=pos-nb;
        tot+=(n-pos-1)-(tota-nb-1);
        maxi=min(maxi,tot);
    }
    return maxi;    
}

void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    ll maxi=999999999999;
    int tota=0;
    rep(i,0,n){
        if (s[i]=='a')tota++;
    }
    vector<pair<int,int>> characs;
    int curA=0;
    rep(i,0,n){
        if (s[i]=='a'){ characs.push_back({i,curA});
            curA++;
        }
    }
    ll tot=0;
    for (auto [pos,nb] : characs){
        tot+=pos-nb;
    }
    maxi=min(maxi,tot);
    for (int i=characs.size()-1;i>=0;i--){
        auto [pos,nb] = characs[i];
        tot-=pos-nb;
        tot+=(n-pos-1)-(tota-nb-1);
        maxi=min(maxi,tot);
    }

    rep(i,0,n) s[i]=(s[i]=='a'?'b':'a');
    maxi=min(maxi,solve2(s));
    cout<<maxi<<"\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t=get();
    rep(i,0,t)
    solve();
}