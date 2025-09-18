#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>

const int N = 1e6;

void phi_1_to_n(int n, vector<ll>& cumsum) {
    vector<int> phi(n + 1);
    phi[0] = 0;
    phi[1] = 1;
    cumsum[1]=1LL;
    for (int i = 2; i <= n; i++)
        phi[i] = i - 1;

    for (int i = 2; i <= n; i++)
        for (int j = 2 * i; j <= n; j += i)
              phi[j] -= phi[i];
    
    for (int i=2; i<=n;i++){
        cumsum[i]=cumsum[i-1]+(ll)phi[i];
    }

//    for (int i=0; i<20; i++) cout<<cumsum[i]<<" ";
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll k;
    cin>>k;
    vector<ll> cumsum(N+1);
    phi_1_to_n(N, cumsum);
    while(k!=0LL){
        if (k==1) cout<<"0/1\n";
        else if (k==2) cout<<"1/1\n"; 
        else{
            k--;
            int l=0;
            int r=N+1;
            int mid;
            while (r>l){
                mid=(l+r)/2;
                if (cumsum[mid]>=k){
                    r=mid;
                }
                else l=mid+1;
//                cout<<k<<l<<r<<endl;
            }
 //           cout<<l<<"  "<<flush;
            int tot=1;
            int tmp=k-cumsum[l-1];
            while (tmp){
                if (gcd(tot, l)==1){
                    tmp--;
                }
                tot++;
            }
            tot--;
            cout<<tot;
            cout<<"/"<<l<<endl;
        }
        cin>>k;
    }
}