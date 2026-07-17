#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define vi vector<int>
#define vl vector <ll>

int main(){
    int t;
    cin >> t;
    while (t--){
        ll n,k;
        cin >>n>>k;
        vl a(n);
        vl b(n);
        for (auto& x : a) cin >> x;
        for (auto& x : b) cin >> x;
        ll x=-1;
        ll maxaDoute= -1; // Plus grand elem a ajuster
        ll minaDoute= LLONG_MAX; // PLus petit
        bool fini=false;
        for (int i=0;i<n;i++){
            if (b[i]!=-1){
                if (x==-1){
                    x=a[i]+b[i];
                }
                else if (a[i]+b[i]!=x){
                    fini=true;
                }
            }
            else{
                if (a[i]<minaDoute){
                    minaDoute=a[i];
                }
                else if ((a[i]>maxaDoute)){
                    maxaDoute=a[i];
                }

            }
        }
        if (fini){
            cout<<0<<endl;
        }
        else{
            if (x==-1){
                cout<<max(0LL, k-(*max_element(a.begin(), a.end()) - *min_element(a.begin(), a.end()))+1)<<endl;
            }
            else{
                if (x-minaDoute>k){
                    cout<<0<<endl;
                }
                else if (maxaDoute>x){
                    cout<<0<<endl;
                }
                else{
                    cout<<1<<endl;
                }
            }
        }
    }
}