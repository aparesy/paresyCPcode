#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define vi vector<int>
#define vl vector <ll>

int main(){
    int t;
    cin >> t;
    while (t--){
        int n;
        int x;
        cin>>n>>x;
        vector<int> v(n);
        for (auto& x : v)cin>>x;
        sort(v.begin(), v.end());
        int maxi=0;
        for (int i=0;i<n-1;i++){
            if (v[i+1]-v[i]>maxi){
                maxi = v[i+1]-v[i];
            }
        }
        if (2*(x-v[n-1])>maxi){
            maxi = 2*(x-v[n-1]);
        }
        if (v[0]>maxi){
            maxi=v[0];
        }
        cout<<maxi<<endl;
    }
}