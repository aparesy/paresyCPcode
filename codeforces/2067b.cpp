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
        vl v(n);
        for (auto& x : v)cin>>x;
        sort(v.begin(),v.end());
        int i=0;
        bool fini=false;
        while (i<n && !fini)
        {
            int elem=v[i];
            int count=0;
            if (v[i+1]==elem)
        }
        if (fini) cout<<"No\n";
        else cout<<"Yes\n";
        
    }
}