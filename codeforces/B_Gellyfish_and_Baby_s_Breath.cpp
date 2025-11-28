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

ll mod=998244353ll;

ll tab[100001];
#define puiss(n) tab[n]

void solve(){
    int n=get();
    vi p(n);
    vi q(n);
    input(p);
    input(q);
    vi prefP(n);
    vi prefQ(n);
    prefP[0]=p[0];
    prefQ[0]=q[0];
    cout<<((puiss(p[0])+puiss(q[0]))%mod)<<" ";
    int indP=0;
    int indQ=0;
    rep(i,1,n){
        if (p[i]>prefP[i-1]) indP=i;
        if (q[i]>prefQ[i-1]) indQ=i;
        prefP[i]=max(prefP[i-1],p[i]);
        prefQ[i]=max(prefQ[i-1],q[i]);
        if (prefP[i]>prefQ[i]){
            cout<<((puiss(p[indP])+puiss(q[i-indP]))%mod)<<" ";
        }
        else if (prefQ[i]>prefP[i]){
            cout<<((puiss(p[i-indQ])+puiss(q[indQ]))%mod)<<" ";
        }
        else{
            if (q[i-indP]>p[i-indQ]){
                cout<<((puiss(p[indP])+puiss(q[i-indP]))%mod)<<" ";
            }
            else{
                cout<<((puiss(p[i-indQ])+puiss(q[indQ]))%mod)<<" ";
            }
        }
    }
    cout<<"\n";

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    tab[0]=1;
    rep(i,0,100000){
        tab[i+1]=tab[i]*2ll;
        tab[i+1]%=mod;
    }
    int t; cin>>t; rep(i,0,t)
    solve();
}