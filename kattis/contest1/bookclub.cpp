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

void SCC(vvi& graph, bool& ok){
    int n=graph.size();
    int timer=0;
    vi val(n,0), stk, cont;
    function<int(int)> dfs = [&](int node){
        int low; low=val[node]=++timer;
        int sz=stk.size(); stk.push_back(node);
        for (auto vec : graph[node])
            if (val[vec]!=-1){
                low=min(low,val[vec]?:dfs(vec));
            }
        if (low==val[node]){
            cont={stk.begin()+sz,stk.end()};
            for (auto x : cont) val[x]=-1;
            if (cont.size()==1)ok=false; stk.resize(sz);
        } else val[node]=low;
        return low;
    };
    for (int i=0;i<n;++i){
        if (val[i]!=-1) dfs(i);
    }

}

void solve(){
    int n,m;
    cin>>n>>m;
    vvi graph(n);
    rep(i,0,m){
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
    }
    bool ok=true;
    SCC(graph, ok);
    if (ok) cout<<"YES\n";
    else cout<<"NO\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}