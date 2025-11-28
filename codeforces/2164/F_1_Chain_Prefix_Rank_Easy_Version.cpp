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

bool verifyCorrect(vvi& children, vi& a, int s, int depth){
    if (a[s]>depth) return false;
    for (auto x : children[s]){
        if (!verifyCorrect(children, a, x, depth+1)) return false;
    }
    return true;
}

ll mod=998244353ll;

ll fact[100001];

ll inv(ll a){
    return a <= 1 ? a : mod - (long long)(mod/a) * inv(mod % a) % mod;
}

void dfsGetTmp(vvi& children, vi& a, int s, vii& tmp, int i, int curPlaceRoot, vb& places){
    // On est dans tmp[i]
    tmp[i].first++;
    if (places[s]) tmp[i].first--;
    if (curPlaceRoot>=a[s] && !places[s]){
        tmp[i].second++;
        curPlaceRoot++;
        places[s]=true;
    }
    for (auto x : children[s]){
        dfsGetTmp(children, a, x, tmp, i, curPlaceRoot, places);
    }
}

ll dfs(vvi& children, vi& a, int s, vb& places){
    int curPlaceRoot=a[s];
    vii tmp(children[s].size()); // On va stocker le nombre d'enfants et le nombre d'inférieurs
    rep(i,0,children[s].size()){
        int t=children[s][i];
        dfsGetTmp(children, a, t, tmp, i, curPlaceRoot, places);
    }
    // Now we got branch info
    int sum=0;
    int sum2=0;
    rep(i,0,children[s].size()){
        sum+=tmp[i].second;
        sum2+=tmp[i].first-tmp[i].second;
    }
    ll tot=fact[sum];
    rep(i,0,children[s].size()){
        tot*=inv(fact[tmp[i].second]);
        tot%=mod;
        tot*=dfs(children, a, children[s][i], places);
        tot%=mod;
        tot*=inv(fact[tmp[i].first-tmp[i].second]);
        tot%=mod;
    }
    tot*=fact[sum2];
    tot%=mod;
    return tot;
}

void solve(){
    int n=get();
    vi parent(n-1);
    input(parent);
    rep(i,0,n-1){
        parent[i]--;
    }
    vvi children(n);
    rep(i,0,n-1){
        children[parent[i]].push_back(i+1);
    }
    vi a(n);
    input(a);
    if (!verifyCorrect(children, a, 0, 0)){
        cout<<0<<"\n";
        return;
    }

    vb places(n);
    cout<<dfs(children, a, 0, places)<<"\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    fact[0]=1;
    rep(i,1,100001){
        fact[i]=(fact[i-1]*(ll)i)%mod;
    }
    int t; cin>>t; rep(i,0,t)
    solve();
}