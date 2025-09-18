#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define pdd pair<double,double>
#define vi vector<int>
#define vii vector<pii>
#define vvi vector<vector<int>>
#define ll long long
#define vl vector<ll>
#define vvl vector<vector<ll>>
#define vb vector<bool>
#define F first 
#define S second
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define input(tab) for (auto& x : tab)cin>>x

void solve(){
    ll n;
    cin>>n;
    vl a(n);
    input(a);
    vl b(n);
    input(b);
    ll tot=0LL;

    vl maxA(n);
    maxA[0]=a[0];
    rep(i,1,n){
        maxA[i]=max(maxA[i-1],a[i]);
    }
    
    vector<pair<ll,ll>> mQueue;
    rep(i,0,n){
        if (a[i]==b[i]){
            tot+=(i+1LL)*(n-i);
        }
        else if (i!=0 &&b[i]<=maxA[i] && a[i]<=maxA[i-1]){
    //         int l=-1; int r=mQueue.size();
    //         while (r-l>1){
    //             int m=(l+r)/2;
    //             if (mQueue[m].first<b[i]) r=m;
    //             else l=m;
    //    //         cout<<l<<" ";
    //         }
            // Le bon élém se trouve en mQueue[l].second
            while(mQueue.size()>=1 && mQueue[mQueue.size()-1].first<a[i]){
                mQueue.pop_back();
            }
            mQueue.push_back({a[i],i});
            if (mQueue[0].first >= b[i]){
                tot+=(mQueue[mQueue.size()-1].second+1LL-(mQueue.size()==1?0:mQueue[mQueue.size()-2].second))*(n-i);
            }
        }
        else{
            while(mQueue.size()>=1 && mQueue[mQueue.size()-1].first<a[i]){
                mQueue.pop_back();
            }
            mQueue.push_back({a[i],i});
        }
    }
    cout<<tot<<"\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    rep(i,0,t)
    solve();
}