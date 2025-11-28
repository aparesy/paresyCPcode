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

const int maxn=3e5+1;


bool vu[maxn];
int parity[maxn];
bool mainBranch[maxn];

bool dfs(int s, vvi& adj, vi& cumul){
    bool ok=mainBranch[s];
    for (auto t : adj[s]){
        if (!vu[t]){
            vu[t]=true;
            parity[t]=1-parity[s];
            ok |= dfs(t,adj,cumul);
        }
    }
    if (ok){
        mainBranch[s]=true;
    }
    else{
        mainBranch[s]=false;
    }
    cumul.push_back(s);
    return mainBranch[s];
}


void solve(){
    int n;
    cin>>n;
    vvi adj(n);
    rep(i,0,n-1){
        int a,b;
        cin>>a>>b;
        a--;b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    fill(vu, vu+n, false);
    fill(mainBranch, mainBranch+n,false);
    fill(parity,parity+n,0);
    mainBranch[n-1]=true;
    mainBranch[0]=true;
    parity[0]=0;
    vu[0]=true;
    vi cumul(0);
    dfs(0,adj,cumul);

    vii ops;
    int curParity=0;
    for (auto s : cumul){
        if (!mainBranch[s]){
            if (parity[s]!=curParity){
                ops.push_back({2,s+1});
                ops.push_back({1,-1});
                curParity=1-curParity;
            }
            else{
                ops.push_back({1,-1});
                ops.push_back({2,s+1});
                ops.push_back({1,-1});
            }
        }
    }

    reverse(all(cumul));

    for (auto s : cumul){
        if (mainBranch[s] && s!=n-1){
            if (parity[s]!=curParity){
                ops.push_back({2,s+1});
                ops.push_back({1,-1});
                curParity=1-curParity;
            }
            else{
                ops.push_back({1,-1});
                ops.push_back({2,s+1});
                ops.push_back({1,-1});
            }
        }
    }
    if (n==1){
        cout<<"0\n\n";
        return;
    }

    if (curParity!=parity[n-1]){

        cout<<ops.size()+1<<"\n";
        ops.push_back({1,-1});
        curParity=1-curParity;

    }
    else{
        cout<<ops.size()<<"\n";
    }
    for (int i=0;i<ops.size();i++){
        auto [type,nb]=ops[i];
        if (type==1){
            cout<<1<<"\n";
        }
        else{
            cout<<2<<" "<<nb<<"\n";
        }
    }
    cout<<"\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin>>t; rep(i,0,t)
    solve();
}