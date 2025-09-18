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
    vi tab(n);
    input(tab);
    int cur=1;
    int i=0;
    int j=n-1;
    rep(k,0,n){
        if (tab[i]==cur){
            i++;
        }
        else if (tab[j]==cur) j--;
        else{
            cout<<"NO\n";
            return;
        }
        cur++;
    }
    cout<<"YES\n";

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    rep(i,0,t)
    solve();
}