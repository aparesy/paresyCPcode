#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vl a(n);
        for (auto& x : a) cin>>x;
        vl b(n);
        for (auto& x : b) cin>>x;
        // Si on bouge, soit le cout (cumsum) est inférieur à n*b
        // Soit on a une case telle que cumsum-cumsum+n*b <=n*b
        // vl cumsum(n,0);
        // cumsum[0]=0;
        // for (int i=1;i<n;i++){
        //     cumsum[i]=cumsum[i-1]+a[i-1];
        // }
        vl locMin(n,-1); // Si -1 : optimal de gamble
        ll cost;
        if (a[n-1]>(n+1)*b[n-1]){
            cost=(n+1)*b[n-1];
        }
        else{
            cost=a[n-1];
            locMin[n-1]=+1;
        }
        for (int i=n-2;i>=0;i--){
            if (cost+a[i] <= (n+1)*b[i]){
                locMin[i]=+1;
                cost+=a[i];
            }
            else{
                cost=(n+1)*b[i];
            }
        }
        for (int i=0;i<n;i++){
            cout<<((locMin[i]==1)?a[i]:(n+1)*b[i])<< " ";
        }
        cout<<endl;
        double tot=0.;
        bool fini=false;
        for (int i=0;i<n && locMin[i]==1;i++){
            tot+=a[i];
            if (i==n-1){
                fini=true;
            }
        }
        if (!fini){
            for (int i=0;i<n;i++){
                tot+=((double)(locMin[i]==1)?a[i]:b[i]*(n+1))/((double)(n+1));
            }
        }
        cout << tot << endl;
    }
}