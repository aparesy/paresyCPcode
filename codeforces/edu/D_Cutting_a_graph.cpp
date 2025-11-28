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

// Go through the orders in reverse order

struct uf{
    vi p;
    vi r;
    void init(int n){
        p.resize(n);
        rep(i,0,n) p[i]=i;
        r.resize(n);
    }

    int get(int a){
        return p[a]=(p[a]==a?a:get(p[a]));
    }

    void uni(int a, int b){
        a=get(a);
        b=get(b);
        if (r[a]==r[b])r[a]++;
        if (r[a]>r[b]){
            p[b]=a;
        }
        else p[a]=b;
    }
};

void solve(){
    int n,m,q;
    cin>>n>>m>>q;n++;
    uf tmp;
    tmp.init(n);
    vector<set<int>> adj(n);
    rep(i,0,m){
        int a,b;
        cin>>a>>b;
        adj[a].insert(b);
        adj[b].insert(a);
    }
    vector<pair<pii,int>> reqs;
    rep(i,0,q){
        string s;
        cin>>s;
        int a,b;cin>>a>>b;
        if (s[0]=='a'){
            reqs.push_back({{a,b},1});
        }
        else{
            reqs.push_back({{a,b},2});
            adj[a].erase(b);
            adj[b].erase(a);
        }
    }
    rep(i,0,n){
        for (auto b : adj[i]){
            tmp.uni(b,i);
        }
    }
    stack<bool> ans;
    for (int i=q-1;i>=0;i--){
        auto [a,b]=reqs[i].first;
        if (reqs[i].second==1){
            ans.push(tmp.get(a)==tmp.get(b));
        }
        else{
            tmp.uni(a,b);
        }
    }
    while (!ans.empty()){
        if (ans.top()){
            cout<<"YES\n";
        }
        else cout<<"NO\n";
        ans.pop();
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}