#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        vector<int> v(n);
        for (auto& x : v){
            cin >> x;
        }
        sort(v.begin(), v.end());
        int i=0;
        bool fini=false;
        int state=4;
        while (i<n&&!fini){
            int count=1;
            while (i+1<n && v[i]==v[i+1]){
                count++;
                i++;
            }
            if (count>=4){
                fini=true;
            }
            if (count==3 || count==2 ){
                if (state<=2){
                    fini=true;
                }
                else state=2;
            }
            if (i+1<n && v[i+1]-v[i]>1) state=4;
            i++;
        }
        if (fini) cout << "Yes"; else cout << "No"; cout << endl;
    }
}