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
    if (n==1){
        cout<<0<<"\n";
        return;
    }
    int i=0;
    int maxi=0;
    int max_i=0;
    while (i<n-1 && (tab[i]+tab[n-1])%2){
        if (tab[i]>maxi){
            maxi=tab[i];
            max_i=i;
        }
        i++;
    }
    // Propagation vers l'avant
    vector<pii> instr;
    instr.push_back({max_i,n-1});
    tab[n-1]=tab[max_i];
    // Propagation vers l'arrière
    rep(j,0,i){
        instr.push_back({j,n-1});
    }
    rep(j,i,n-1){
        if ((tab[j]+tab[n-1])%2){
            instr.push_back({max_i,j});
        }
        else instr.push_back({j,n-1});
    }
    cout<<instr.size()<<"\n";
    for (auto [a,b] : instr){
        cout<<a+1<<" "<<b+1<<"\n"
;    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    rep(i,0,t)
    solve();
}