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
        int n;
        cin>>n;
        int x;
        cin>>x;
        vl v(n);
        for (auto& y : v)cin>>y;
        int mini=n;
        int maxi=0;
        for (int i=0;i<n;i++){
            if (mini==n && v[i]==1){
                mini=i;
            }
            if (v[i]==1){
                maxi=i;
            }
        }
        if (maxi-mini>=x){
            cout<<"NO\n";
        }
        else cout<<"YES\n";
    }
}