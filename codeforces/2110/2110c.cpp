#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        vector<int> d(n);
        for (auto& x : d) cin >> x;
        vector<int> l(n);
        vector<int> r(n);
        for (int i=0;i<n;i++){
            cin >> l[i] >> r[i];
        }

        bool fini=false;
        int minH=0;
        int maxH=0;
        for (int i=0;i<n;i++){
            if (d[i]==0){

            }
            else if (d[i]==1){
                minH++;
                maxH++;
            }
            else{
                maxH++;
            }
            if (minH > r[i]) fini=true;
            if (maxH<l[i]) fini=true;
            maxH = min(maxH, r[i]);
            minH = max(minH, l[i]);
        }
        if (fini) cout << -1;
        else{
            vector<int> lowest(n,0);
            lowest[n-1] = r[n-1]-(d[n-1]==1);
            for(int i=n-2;i>=0;i--){
                lowest[i] = min(r[i], lowest[i+1])-(d[i]==1);
            }
            int curH=0;
            for (int i=0;i<n;i++){
                if (d[i]==-1){
                    if (curH < lowest[i]){
                        curH++;
                        cout << 1;
                    }
                    else{
                        cout << 0;
                    }
                }
                else{
                    cout << d[i];
                    curH+=d[i];
                }
                cout << " ";
            }
        }
        cout << endl;
    }
}