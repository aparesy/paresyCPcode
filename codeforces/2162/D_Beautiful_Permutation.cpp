// Useful functions : nth_element, rotate, unique, merge, count, generate

#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define pdd pair<double,double>
#define vi vector<int>
#define vii vector<pii>
#define vvi vector<vector<int>>
using ll=long long;
#define vl vector<ll>
#define vvl vector<vector<ll>>
#define vb vector<bool>
#define F first 
#define S second
#define rep(i,a,b) for(int i=a;i<b;i++)
#define input(tab) for (auto& x : tab)cin>>x
#define all(x) x.begin(),x.end()

ll get(){
   ll x;
   cin>>x;
   return x;
}

int req1(int l, int r){
    cout<<1<<" "<<l+1<<" "<<r+1<<"\n"<<flush;
    int x;
    cin>>x;
    return x;
}

int req2(int l, int r){
    cout<<2<<" "<<l+1<<" "<<r+1<<"\n"<<flush;
    int x;
    cin>>x;
    return x;
}

void ans(int l, int r){
    cout<<"! "<<l+1<<" "<<r+1<<"\n"<<flush;
}
void solve(){
    int n=get();
    int length=req2(0,n-1)-req1(0,n-1);
    int l=0;
    int r=n;
    while (r-l>length){
        int m=(r+l)/2;
        int tot=req2(0,m-1)-req1(0,m-1);
        if (tot==0){
            l=m;
        }
        else if (tot==length){
            r=m;
        }
        else{
            l=m-tot;
            r=l+length;
        }
    }
    ans(l,r-1);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin>>t; rep(i,0,t)
    solve();
}