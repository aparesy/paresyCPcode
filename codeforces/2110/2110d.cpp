#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    int t;
    cin >> t;
    while (t--){
        int n,m;
        cin >> n >> m;
        vector<ll> b(n);
        for (auto& x : b) cin >> x;
        vector<pair<int,ll>> g[n];
        int x,y;
        ll z;
        for (int i=0;i<m;i++){
 //           cout << "ok" << endl;
            cin >> x>>y>>z; x--;y--;
            g[x].push_back(make_pair(y,z));
  //          cout << x << " " << y;
        }
        priority_queue<tuple<ll,int,ll>> q;
        q.push({0,0,0});
        bool fini=false;
        while (!q.empty() && !fini){
            tuple<ll,int,ll> t = q.top();
            ll minB = -get<0>(t); int s = get<1>(t); ll maxB = get<2>(t);
   //         cout << minB << " " << s << " " << maxB << endl;
            q.pop();
            if (s==n-1){
                fini=true;
                cout << minB;
            }
            else{
    //            cout << s << " "<< g[s].size() << endl;
                for (auto neighbor : g[s]){
    //                cout << "ok" << endl;
                    if (maxB+b[s] >= neighbor.second){
                        q.push(make_tuple(-max(minB, neighbor.second), neighbor.first, maxB+b[s]));
                    }
                }
            }
        }
        if (!fini) cout << -1;
        cout << endl;
    }
}