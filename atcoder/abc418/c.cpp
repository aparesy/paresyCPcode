#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pii>
#define vvi vector<vector<int>>
#define ll long long
#define vl vector<ll>
#define rep(i,a,b) for(int i=a;i<b;i++)

void solve(){
    ll n,q;
    cin>>n>>q;
    vl tab(n);
    for (auto& x : tab) cin>>x;
    sort(tab.begin(), tab.end());
    vl cumsum(n);
    cumsum[0]=tab[0];
    rep(i,1,n){
        cumsum[i]=cumsum[i-1]+tab[i];
    }
    ll b;
    rep(i,0,q){
        cin>>b;
        if (b>tab[n-1]) cout<<-1<<endl;
        else{
            int l=0;
            int r=n-1;    
            while(l<r){
                int mid=(l+r)/2;
                if (tab[mid]>=b){
                    r=mid;
                }
                else l=mid+1;
            }
            ll tot=0LL;
            if (l) tot+=cumsum[l-1];
            cout<<tot+(n-l)*(b-1LL)+1LL<<endl;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}