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

// const int MAXN=3e5;
// ll t[2][MAXN];
// ll nb[2][MAXN];

void solve(){
    int n=get();
    string a,b;
    cin>>a>>b;
    int tot=1;
    vector<int> path;
    path.push_back(a[0]-'0');
    rep(i,0,n-1){
        int c1=(a[i+1]-'0');
        int c2=(b[i]-'0');
        if (c1==c2){
            tot++;
            path.push_back(c1);
        }
        else{
            if (c2>c1){
                tot=1;
                path.push_back(c1);
            }
            else{
                for (auto x : path)cout<<x;
                cout<<c2;
                rep(j,i+1,n) cout<<(b[j]-'0');
                cout<<"\n"<<tot<<"\n";
                return;
            }
        }
    }

        for (auto x : path)cout<<x;
        cout<<b[n-1]-'0';
        cout<<"\n"<<tot<<"\n";

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin>>t; rep(i,0,t)
    solve();
}