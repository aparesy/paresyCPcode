#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define vi vector<int>
#define vl vector <ll>

int main(){
    int t;
    cin >> t;
    while (t--){
        int n,k;
        cin>>n>>k;
        vector<int> v(n);
        for (auto& x : v)cin>>x;

        if (find(v.begin(), v.end(), k) != v.end()) cout<<"YES\n"; else cout<<"NO\n";
    }
}