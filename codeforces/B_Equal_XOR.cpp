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
    int n,k;
    cin>>n>>k;
    vl tab(2*n);
    input(tab);
    // Trivial just find elem type;
    vi side(n+1);
    rep(i,n,2*n){
        side[tab[i]]++;
    }
    int compteZ=0;
    int compteU=0;
    int compteD=0;
    vi tab1;
    vi tab2;
    stack<int> single;
    rep(i,0,2*n){
        if (side[tab[i]]==0 && compteZ*2+compteU+2<=2*k){
            tab1.push_back(tab[i]); tab1.push_back(tab[i]);
            side[tab[i]]=-1;
            compteZ++;
        }
        else if (side[tab[i]]==2 && compteD*2+compteU+2<=2*k){
            tab2.push_back(tab[i]); tab2.push_back(tab[i]);
            side[tab[i]]=-1;
            compteD++;
        }
        else if (side[tab[i]]==1 && max(compteZ,compteD)*2+compteU+1<=2*k){
            single.push(tab[i]);
            side[tab[i]]=-1;
        }
    }
    while (max(compteZ,compteD)*2+compteU+1<=2*k){
        compteU++;
        int k = single.top();
        single.pop();
        tab1.push_back(k); tab2.push_back(k);
    }
    for (auto x : tab1)cout<<x<<" ";
    cout<<endl;
    for (auto x  :tab2)cout<<x<<" ";
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