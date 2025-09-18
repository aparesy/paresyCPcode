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
    int n,l;
    cin>>n>>l;
    vvi adj(n);
    rep(i,0,n-1){
        int a,b;
        cin>>a>>b;
        a--;b--;
        adj[a].push_back(b); adj[b].push_back(a);
    }
    vector<vi> lab(n,vi(26));

    vb vu1(n);
    vb vu2(n);

    rep(i,0,l){
        int cur;
        string s;
        cin>>cur>>s;
        cur--;
        if (s[0]!='$'){
            rep(j,0,s.length()){
                lab[cur][s[j]-'A']=true;
            }
        }
        vu2[cur]=true;
    }
    ll tot=0;
    rep(c,0,26){

    }
    cout<<tot;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}