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

void solve(){
    int n;
    cin>>n;
    int q=get();
    rep(i,0,q){
        string s;
        cin>>s;
        if (s[0]=='-'){
            ll x,y;
            cin>>x>>y;
            x--;
            y--;
            ll offset=n-1;
            ll tot=0;
            rep(i,0,n){
                tot*=4ll;
                int c1 = (x&(1ll<<offset));
                int c2 = (y&(1ll<<offset));
                if (c1 && c2){
                    tot+=1ll;
                }
                else if (c1){
                    tot+=2ll;
                }
                else if (c2){
                    tot+=3ll;
                }
                offset--;
            }
            cout<<tot+1<<"\n";
        }
        else{
            ll x;
            cin>>x;x--;
            ll rex=1;
            ll rey=1;
            ll offset=1;
            rep(i,0,n){
                ll c=x%4ll;
                x/=4ll;
                if (c==1){
                    rex+=offset; rey+=offset;
                }
                else if (c==2){
                    rey+=offset;
                }
                else if (c==3){
                    rex+=offset;
                }
                offset*=2ll;
            }
            cout<<rey<<" "<<rex<<"\n";
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin>>t; rep(i,0,t)
    solve();
}