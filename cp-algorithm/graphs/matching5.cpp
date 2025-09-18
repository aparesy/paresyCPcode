#include <bits/stdc++.h>
using namespace std;

vector<bool> used;

bool try_kuhn(int v, vector<vector<int>>& g, vector<int>& mt, int n) {
    if (used[v])
        return false;
    used[v] = true;
    //cout<<v<<" "<<g[v].size()<<endl;
    for (int to : g[v]) {
        if (mt[to-n] == -1 || try_kuhn(mt[to-n],g,mt,n)) {
            
            mt[to-n] = v; 
            return true;
        }
    }
    return false;
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n,m,s,v;
    while (cin>>n>>m>>s>>v){
        vector<pair<double,double>> loc(n);
        double tmp1,tmp2;
        for (int i=0;i<n;i++){
            cin>>tmp1>>tmp2;
            loc[i]={tmp1,tmp2};
        }
        vector<vector<int>> adj(n+m);
        for (int i=0;i<m;i++){
            cin>>tmp1>>tmp2;
            for (int j=0;j<n;j++){
                if ((tmp1-loc[j].first)*(tmp1-loc[j].first)+(tmp2-loc[j].second)*(tmp2-loc[j].second) <= (double)v*v*s*s){
                    adj[i+n].push_back(j);
                    adj[j].push_back(i+n);
                }
            }
        }
        vector<int> mt(m,-1);
        for (int v=0;v<n;v++){
            used.assign(n,false);
            try_kuhn(v,adj,mt,n);
        }
        int count=0;
        for (int i=0;i<m;i++) if (mt[i]!=-1) count++;
        cout<<n-count<<endl;
    }
}