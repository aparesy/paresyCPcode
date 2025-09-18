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
#define rep(i,a,b) for(int i=a;i<b;i++)
#define input(tab) for (auto& x : tab)cin>>x

struct tuple_hash {
    template <class T1, class T2, class T3>
    size_t operator() (const std::tuple<T1, T2, T3>& t) const {
        auto h1 = std::hash<T1>{}(std::get<0>(t));
        auto h2 = std::hash<T2>{}(std::get<1>(t));
        auto h3 = std::hash<T3>{}(std::get<2>(t));
        // Combine the hashes
        return h1 ^ (h2 << 1) ^ (h3 << 2);
    }
};

void compute(vi& tab, int i, int seuil1, int seuil2, unordered_map<tuple<int,int,int>, ll, tuple_hash>& h, int n, ll mod){
    if (i==n) h[make_tuple(i,seuil1,seuil2)]=1;
    if (h.find(make_tuple(i,seuil1,seuil2)) != h.end()){
        return;
    }
    compute(tab,i+1,seuil1,seuil2,h,n,mod);
    ll res=h[make_tuple(i+1,seuil1,seuil2)];
    if (tab[i]>=seuil2){
        compute(tab,i+1,seuil1,tab[i],h,n,mod);
        res+=h[make_tuple(i+1,seuil1,tab[i])];
    }
    else if (tab[i]>=seuil1){
        compute(tab,i+1,tab[i],seuil2,h,n,mod);
        res+=h[make_tuple(i+1,tab[i],seuil2)];
    }
    h[make_tuple(i,seuil1,seuil2)]=res%mod;
}

void solve(){
    int n;
    cin>>n;
    ll mod=1e9+7LL;
    vi tab(n);
    input(tab);
    unordered_map<tuple<int,int,int>, ll, tuple_hash> h;
  //  compute(tab,0,0,0,h,n,mod);

    ll res[n+1][n+1][n+1];
    rep(i,0,n+1){
        rep(j,0,n+1){
            res[n][i][j]=1;
        }
    }
    for (int i=n-1;i>=0;i--){
        rep(j,0,n+1){
            rep(k,0,n+1){
                res[i][j][k]=res[i+1][j][k];
                if (tab[i]>=k){
                    res[i][j][k]+=res[i+1][j][tab[i]];
                }
                else if (tab[i]>=j){
                    res[i][j][k]+=res[i+1][tab[i]][k];
                }
                if (res[i][j][k]>=mod) res[i][j][k]%=mod;
            }
        }
    }
    cout<<res[0][0][0]<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    rep(i,0,t)
    solve();
}