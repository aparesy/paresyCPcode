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
        vector<vector<ll>> v(n);
        int m;
        vl minis(n,LLONG_MAX);
        vl minis2(n,LLONG_MAX);
        for (int i=0;i<n;i++){
            cin>>m;
            v[i].resize(m);
            for (auto& x : v[i]) cin>>x;
            for (auto x : v[i]){
                if (x<=minis2[i]){
                    if (x<=minis[i]){
                        minis2[i]=minis[i];
                        minis[i]=x;
                    }
                    else minis2[i]=x;
                }
            }
        }
        //foreach tab, the loss is 2ndmin-1stmin + 1stmin-minofmins = 2ndmin - minofmins. we want to minimize this value.
        int imin = 0;
        for (int i=0;i<n;i++){
            if (minis2[i]<minis2[imin]){
                imin=i;
            }
        }
        ll minofmins=LLONG_MAX;
        for (int i=0;i<n;i++){
            if (minis[i]<minofmins){
                minofmins=minis[i];
            }
        }
        ll tot=0;
        for (int i=0;i<n;i++){
            if (i==imin){
                tot+=minofmins;
            }
            else{
                tot+=minis2[i];
           //     cout<<minis2[i]<<endl;
            }
        }
        cout<<tot<<endl;
    }
}