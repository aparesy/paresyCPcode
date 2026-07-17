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
    int n,m;
    cin>>n>>m;
    vector<string> a(n);
    vector<vector<string>> b(m, vector<string>(n));
    input(a);
    rep(i,0,m){
        input(b[i]);
    }
    rep(i,0,n){
        bool ok=false;
        rep(j,0,m){
            if (a[i].compare(b[j][i])==0) ok=true;
        }
        if (!ok){
            cout<<-1<<"\n";
            return;
        }
    }
    
    vector<bitset<501>> tab(m);
    rep(i,0,m){
        int common=0;
        rep(j,0,n){
            if (a[j].compare(b[i][j])==0) tab[i][j]=1;
        }
    }

    ll tot=n; // treat the first apart
    bool premier=true;
    bitset<501> notFound;
    rep(i,0,n) notFound[i]=1;
    while (notFound.count()){
        int maxi=0;
        int maxInd=0;
        rep(i,0,m){
            if (maxi<(notFound&tab[i]).count()){
                maxInd=i;
                maxi=(notFound&tab[i]).count();
            }
        }
        if (!premier) tot+=maxi*2;
        notFound &= (tab[maxInd].flip());
        premier=false;
    }
    cout<<tot<<"\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin>>t; rep(i,0,t)
    solve();
}