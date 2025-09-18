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
        ll a1 = v[0] - (n*((2*v[0])-v[1]))/(n+1);
        ll a2 = (2*v[0]-v[1])/(n+1);
        bool fini=false;
        if ((2*v[0]-v[1]) % (n+1) != 0) fini=true;
        if (n*((2*v[0])-v[1]) % (n+1) != 0) fini=true;  
        if (a1<0 || a2<0) fini=true;
        for (int i=0;!fini&&i<n;i++){
            if ((i+1)*a1 + (n-i)*a2 != v[i]){
                fini=true;
            }
        }
        if (fini) cout<<"NO\n";
        else cout<<"YES\n";
    }
}