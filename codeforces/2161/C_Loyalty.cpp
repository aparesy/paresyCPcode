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
    ll n,x;
    cin>>n>>x;
    vl tab(n);
    input(tab);
    sort(all(tab));
    ll score=0;
    int i=0; int j=n-1;
    ll cur=0;
    vi ordre;
    while (i<=j){
        if (cur+tab[j]>=x){
            cur+=tab[j];
            score+=tab[j];
            ordre.push_back(j);
            j--;
        }
        else{
            cur+=tab[i];
            ordre.push_back(i);
            i++;
        }
        cur%=x;
    }
    cout<<score<<"\n";
    rep(i,0,n){
        cout<<tab[ordre[i]]<<" ";
    }
    cout<<"\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin>>t; rep(i,0,t)
    solve();
}