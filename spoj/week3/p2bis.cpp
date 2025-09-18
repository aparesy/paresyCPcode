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
    vi occ(26);

    rep(i,0,l){
        int cur;
        string s;
        cin>>cur>>s;
        cur--;
        if (s[0]!='$'){
            rep(j,0,s.length()){
                lab[cur][s[j]-'A']=true;
                occ[s[j]-'A']++;
            }
        }
        vu2[cur]=true;
    }
    rep(i,0,26){
        if (occ[i]>=n/2){
            occ[i]=1;
        }
        else occ[i]=0;
    }
    int tot=0;
    rep(i,0,n){
        for (auto t : adj[i]){
            if (vu2[t]){
                rep(i,0,26){
                    tot+=occ[i]^lab[t][i];
                }
            }
        }
    }
    cout<<tot;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}