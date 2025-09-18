#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    while (--t>=0){
        int n,m,l;
        cin >> n >> m >> l;
        vector<int> a(l,0);
        for (int i=0;i<l;i++){
            cin >> a[i];
        }
        vector<int> adj[2*n];
        int e,f;
        for (int i=0;i<m;i++){
            cin >> e >> f;
            e--;f--;
            adj[e].push_back(f+n);
            adj[f].push_back(e+n);
            adj[e+n].push_back(f);
            adj[f+n].push_back(e);
        }
        vector<int> vu(2*n,0);
        vu[0]=true;
        queue<int> q;
        vector<int> dist(2*n,-1);
        dist[0]=0;
        q.push(0);
        while (!q.empty()){
            int s = q.front(); q.pop();
            for (auto u : adj[s]){
                if (vu[u]) continue;
                vu[u] = true;
                dist[u] = dist[s]+1;
                q.push(u);
            }
        }
 //       for (int i=0;i<2*n;i++) cout << dist[i] << " ";
   //     cout << endl;
        int tot=reduce(a.begin(), a.end());
        sort(a.begin(),a.end());
        bool trouve=false;
        int tot2=-1;
//        for (auto v : a) cout << v << " ";
  //      cout << endl;
        for (int i=0;(i<l)&&!trouve;i++){
            if (a[i]%2==1){
                trouve = true;
              tot2=tot-a[i];
   //             cout << "trouve" << a[i] << endl;
            }
        }
        for (int i=0;i<n;i++){
            bool ok=false;
            if (dist[i+n*(tot%2)] != -1 && dist[i+n*(tot%2)]<=tot) ok=true;
            if (trouve && dist[i+n*(tot2%2)] != -1 && dist[i+n*(tot2%2)]<=tot2) ok=true;
            cout << ok;
        }
        cout << endl;
    }
}