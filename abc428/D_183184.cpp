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

void buildCtab(ll c, vi& ctab){
    while(c){
        ctab.push_back(c%10ll);
        c/=10ll;
    }
    reverse(all(ctab));
}

void solve(){
    ll c,d;
    cin>>c>>d;
    vi ctab;
    buildCtab(c,ctab);
    vi dtab;
    buildCtab(c+d,dtab);
    int tot=0;
    int res=0;
    for(ll target=sqrt(c+pow(10,ctab.size())*c);target*target<=pow(10,dtab.size())*c+c+d;target++){
        ll tot=target*target;
        vi tmp;
        buildCtab(tot,tmp);
        bool ok=true;
        rep(i,0,ctab.size()){
            if (tmp[i]!=ctab[i]){
                ok=false;
            }
        }
        if (ok && (tot%((ll)pow(10,ctab.size()))>=c)){
            res++;
        }
    }
    cout<<res<<"\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin>>t; rep(i,0,t)
    solve();
}