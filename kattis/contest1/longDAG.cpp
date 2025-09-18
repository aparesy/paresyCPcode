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

void dfs(int s, vb& vu, vi& ordreDFS, vvi& outEdge){
    for (auto t : outEdge[s]){
        if (!vu[t]){
            vu[t]=true;
            dfs(t,vu,ordreDFS,outEdge);
        }
    }
    ordreDFS.push_back(s);
}

void solve(){
    int n,m;
    cin>>n>>m;
    vvi inEdge(n+1);
    vvi outEdge(n+1);
    vi prec(n+1,-1);
    vi best(n+1,1);
    rep(i,0,m){
        int a,b;
        cin>>a>>b;
        inEdge[b].push_back(a);
        outEdge[a].push_back(b);
    }

    vb vu(n+1,false);
    vi ordreDFS;
    rep(i,1,n+1){
        if (!vu[i]){
            vu[i]=true;
            dfs(i,vu,ordreDFS,outEdge);
        }
    }
    
    for (int i=n-1;i>=0;i--){
        int s=ordreDFS[i];
        for (auto t : inEdge[s]){
            if (best[t]+1>best[s]){
                best[s]=best[t]+1;
                prec[s]=t;
            }
        }
    }

    int maxi=0;
    int maxInd=0;
    rep(i,1,n+1){
        if (best[i]>maxi){
            maxi=best[i];
            maxInd=i;
        }
    }
    cout<<maxi<<endl;
    stack<int> res;
    while(maxInd!=-1){
        res.push(maxInd);
        maxInd=prec[maxInd];
    }
    while(!res.empty()){
        cout<<res.top()<<" ";
        res.pop();
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}