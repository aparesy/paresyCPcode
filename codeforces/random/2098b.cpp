#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while (t--){
        int n,k;
        cin >> n>>k;
        vector<int> v(n);
        for (auto& x : v){
            cin >> x;
        }
        sort(v.begin(),v.end());
        int max_med=1;
        for (int i=0;i<=k;i++){
            if ((n-i)%2==0){
                max_med = max(max_med, v[((n+i)/2)]-v[(n-i)/2-1]+1);
            }
        }
        cout << max_med << endl;
    }
}