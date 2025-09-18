#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    int t;
    cin>>t;
    for (int k=0;k<t;k++){
        ll n;
        cin>>n;
        vector<ll> v(n);
        vector<pair<ll,int>> v2;
        for (auto& x : v){cin>>x;v2.push_back(make_pair(abs(x), x>0?1:-1));}
 //       sort(v.begin(),v.end());
        sort(v2.begin(),v2.end());
        if (n==1){
            cout<<"Yes\n";
            continue;
        }
        if (v2[0].first==0 || v2[1].first==0){
            bool ok=true;
            for (auto x : v){
                if (x!=0) ok=false;
            }
            if (ok){
                cout<<"Yes\n";
            }
            else{
                cout<<"No\n";
            }
            continue;
        }
        if (v2[0].first==v2[1].first){
            ll count=0;
            bool ok=true;
            for (auto x : v2){
                if (x.first != v2[0].first) ok=false;
                count+=x.second;
            }
            if ((count==0 || count==1 || count==-1) && ok){
                cout<<"Yes\n";
                continue;
            }
            else{
                cout<<"No\n";
                continue;
            }
        }
        bool ok=true;
        for (int i=0;i<n-1;i++){
            if (v2[1].first*v2[i].first != v2[0].first*v2[i+1].first) ok=false;
            if (v2[1].second*v2[i].second != v2[0].second*v2[i+1].second) ok=false;
        }
        if (ok){
                cout<<"Yes\n";
            }
        else{
            cout<<"No\n";
        }
    }
}