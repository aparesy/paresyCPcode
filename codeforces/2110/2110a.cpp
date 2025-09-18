#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        vector<int> v(n);
        for (auto& x : v) cin >> x;
        sort(v.begin(), v.end());
        if ((v[0]+v[n-1])%2==0){
            cout << 0 << endl;
        }
        else{
            int a=0;
            while(!((v[a]+v[a+1])%2)) a++;
            int b=n-1;
            while(!((v[b]+v[b-1])%2))b--;
            cout << min(a+1, n-b) << endl;
        }
    }
}