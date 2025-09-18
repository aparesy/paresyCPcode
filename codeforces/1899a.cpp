#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define vi vector<int>
#define vl vector <ll>

int main(){
    int t;
    cin >> t;
    while (t--){
        int n;cin>>n;
        vi v(n);
        for (auto& x : v) cin>>x;
        if (v[0]==1){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
    }
}