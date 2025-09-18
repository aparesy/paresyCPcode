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
    sort(tab.begin(),tab.end());
    ll cur=0LL;
    for (int i=0;i<n;i++){
        if (tab[i]>cur+1LL){
            cout<<cur+1LL;
            return;
        }
        cur+=tab[i];
    }
    cout<<cur+1LL;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}