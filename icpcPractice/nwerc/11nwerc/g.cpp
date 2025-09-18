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
#define rep(i,a,b) for(int i=a;i<b;i++)

double dist(pair<double, double>& p1, pair<double, double>& p2){
    return hypot(p1.first-p2.first, p1.second-p2.second);
}

void dfs(int s, vvi& adj, vector<bool>& vuDFS, vector<bool>& vu, vi& ordre){
    for(auto t : adj[s]){
        if (!vuDFS[t]){
            vuDFS[t]=true;
            dfs(t,adj,vuDFS,vu,ordre);
        }
    }
    ordre.push_back(s);
}

bool dfs2(int s, vvi& adj, vector<bool>& vuDFS){
    for (auto t:adj[s]){
        if (vuDFS[t]) return false;
        vuDFS[t]=true;
        if (!dfs2(t,adj,vuDFS)) return false;
    }
    return true;
}

void solve(){
    int n;
    int claims;
    cin>>n>>claims;
    unordered_map<string, int> numberOfName;
    vector<string> NameofNumber;
    vector<pair<double,double>> points(n);
    vvi adj(n);
    vector<bool> vu(n);
    rep(i,0,n){
        string s;
        cin>>s;
        NameofNumber.push_back(s);
        numberOfName[s]=i;
        double x,y;
        cin>>x>>y;
        points[i]={x,y};
    }
    rep(i,0,claims){
        string s;
        cin>>s;
        int a=numberOfName[s];
        cin>>s; cin>>s;
        int b=numberOfName[s];
        cin>>s; cin>>s; cin>>s;
        int c=numberOfName[s];
        double d1=dist(points[b], points[a]);
        double d2=dist(points[c],points[a]);
        if (abs(d1-d2)<pow(10.,-10.) || d1>d2){
            adj[b].push_back(c);
        }
        vu[b]=true;
        vu[c]=true;
    }
    vector<int> ordre;
    vector<bool> vuDFS(n,false);
    rep(i,0,n){
        if (!vuDFS[i] && vu[i]){
            vuDFS[i]=true;
            dfs(i, adj, vuDFS, vu, ordre);
        }
    }

    vvi invAdj(n);
    rep(i,0,n){
        for (auto x : adj[i]){
            invAdj[x].push_back(i);
        }
    }

    vuDFS.assign(n,false);
    for (int i=ordre.size()-1;i>=0;i--){
        if (vuDFS[i]){
            cout<<"IMPOSSIBLE\n";
            return;
        }
        vuDFS[i]=true;
        if (!dfs2(i, invAdj, vuDFS)){
            cout<<"IMPOSSIBLE\n";
            return;
        }
    }

    vuDFS.assign(n,false);
    vuDFS[ordre.back()]=true;
    bool ok=dfs2(ordre.back(), adj, vuDFS);
    rep(i,0,n){
        if (vu[i]&&!vuDFS[i]){
            cout<<"UNKNOWN\n";
            return;
        }
    }

    for(int i=ordre.size()-1; i>=0;i--){
        if (vu[ordre[i]]){
            cout<<NameofNumber[ordre[i]]<<" ";
        }
    }
    cout<<endl;
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    rep(i,0,t)
    solve();
}