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

vi parent;
vi rang;

void make_set(int v){
    parent[v]=v;
    rang[v]=0;
}

int find_set(int v){
    if (parent[v]==v){
        return v;
    }
    return parent[v]=find_set(parent[v]);
}

void union_sets(int i, int j){
    int a=find_set(i); int b=find_set(j);
    if (a!=b){
        if (rang[a]<rang[b]) swap(a,b);
        parent[b]=a;
        if (rang[a]==rang[b]){
            rang[a]++;
        }
    }
}

void solve(int n){
    vvl dist(n,vl(n));
    priority_queue<pair<ll,pii>,vector<pair<ll,pii>>,greater<pair<ll,pii>>> q;
    rep(i,0,n){
        rep(j,0,n){
            cin>>dist[i][j];
            if (i<j) q.push({dist[i][j],{i,j}});
        }
    }

    parent.resize(n);
    rang.resize(n);
    rep(i,0,n) make_set(i);

    int areteTaken=0;
    bool trouveDehors=false;
    vector<vector<pair<int,ll>>> adj(n);
    while(areteTaken!=n && !q.empty()){
        auto [d,paire]=q.top();
        auto [i,j]=paire;
        q.pop();
        if (find_set(i)!=find_set(j)){
            areteTaken++;
            union_sets(i,j);
            adj[i].push_back({j,d});
            adj[j].push_back({i,d});
            
            cout<<i+1<<" "<<j+1<<" "<<d<<"\n";
        }
        else if (!trouveDehors){
            for (auto [t1,d1] : adj[i]){
                if (dist[t1][j]+d1!=d){
                    cout<<"ok";
                    trouveDehors=true;
                    areteTaken++;
                    cout<<i+1<<" "<<j+1<<" "<<d<<"\n";
                }
            }
        }
    }
    if (!trouveDehors){
        for (int i=0;i<n&&!trouveDehors;i++){
            if (adj[i].size()==1){
                for (int j=0;j<n&&!trouveDehors;j++){
                    if (adj[j].size()==1 && i!=j){
                        cout<<i+1<<" "<<j+1<<" "<<dist[i][j]<<"\n";
                        trouveDehors=true;
                    }
                }
            }
        }
    }
    cout<<"\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    while (cin>>n)
    solve(n);
}