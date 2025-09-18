#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>

int main(){
ios_base::sync_with_stdio(false); cin.tie(0);
  int t;
  cin>>t;
  while(t--){
    ll n,m;
    cin>>n>>m;
    vl a(n);
    vl b(n);
    for (auto& x : a) cin>>x; 
    for (auto& x : b) cin>>x;
    sort(a.begin(), a.end());
    sort(b.begin(),b.end());
    ll tot=0;
    int i=0;
    int j=n-1;
    while (j>=0 && i<n){
        while (a[i]+b[j]<m){
            tot+=a[i];
            i++;
        }
        if (i<n){
            tot+=a[i]+b[j]-m;
            i++;
            j--;
        }
    }
    while (j>=0){
        tot+=b[j];
        j--;
    }

    ll tot2=0;
    i=0;
    j=n-1;
    while (j>=0 && i<n){
        while (b[i]+a[j]<m){
            tot2+=b[i];
            i++;
        }
        if (i<n){
            tot2+=b[i]+a[j]-m;
            i++;
            j--;
        }
    }
    while (j>=0){
        tot2+=a[j];
        j--;
    }

    cout<<min(tot,tot2) << endl;
}
}