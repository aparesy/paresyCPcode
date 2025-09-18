#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define vi vector<int>
#define vl vector <ll>
#define loop(n) for(int i=0;i<n;i++)

int main(){
    int t;
    cin >> t;
    while (t--){
        int n,m;
        cin>>n>>m;
        vector<vector<pair<int,ll>>> adj(n);
        int u,v;
        ll w;
        for (int i=0;i<m;i++){
            cin>>u>>v>>w;
            u--;
            v--;
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        // DJIKSTRA avec priorite := min+max
        vector<unordered_map<ll,int>> vu(n);
        priority_queue<tuple<ll,ll,ll,int>> pq; // min+max, min, max, s
        for (auto vois : adj[0]){
            int s=vois.first;
            w=vois.second;
            pq.push(make_tuple(-2*w,w,w,s));
            vu[s][w]=1;
        }
        bool fini=false;
        while (!fini){
            auto tmp = pq.top();
            pq.pop();
            int s=get<3>(tmp);
            if (s==n-1){
                fini=true;
                cout << -get<0>(tmp)<<endl;
            }
            else{
                for (auto vois : adj[s]){
 //                   cout<<"ok"<<endl;
                    int machin=vois.first;
                    ll poids=vois.second;
                    ll mini=get<1>(tmp);
                    ll nouvPoids=min(mini,poids);
                    if ( vu[machin].find(nouvPoids)==vu[machin].end() || vu[machin][nouvPoids]<100000){
                        
                        ll maxi=get<2>(tmp);
   //                     cout << "Poussé dans le test : " << t << " poids : " << min(mini, w)+max(maxi, w) << " sommet : " << machin<<endl;
                        pq.push(make_tuple(-(nouvPoids+max(maxi, poids)), nouvPoids, max(maxi, poids), machin));
                        if (vu[machin].find(nouvPoids)==vu[machin].end()){
                            vu[machin][nouvPoids]=1;
                        }
                        else vu[machin][nouvPoids]++;
                    }
                }
            }
        }
    }
}