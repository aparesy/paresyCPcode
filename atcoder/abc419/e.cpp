#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define pdd pair<double,double>
#define vi vector<int>
#define vii vector<pii>
#define vvi vector<vector<int>>
#define ll long long
#define vl vector<ll>
#define rep(i,a,b) for(int i=a;i<b;i++)

void solve(){
    int n,m,l;
    cin>>n>>m>>l;
    vi a(n);
    for (auto& x : a)cin>>x;
    vi bestCong(l);
    vi somTot(l,INT_MAX);
    for (int i=0;i<l;i++){
        for (int j=i;j<n;j+=l){
            int sum=0;
            int target=a[j];
            for (int k=i;k<n;k+=l){
                sum+=((a[k]>target)?m-a[k]+target:target-a[k]);
            }
            if (sum<somTot[i]){
                bestCong[i]=target;
                somTot[i]=sum;
            }
        }
    }
    ll tot=0LL;
    for (auto x : somTot) tot+=(ll)x;
    ll somCong=0LL;
    for (auto x : bestCong) somCong+=x;
    somCong%=m;

    cout<<tot+((ll)(n/l)*(m-somCong));
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}