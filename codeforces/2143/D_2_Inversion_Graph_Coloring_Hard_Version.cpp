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


void solve(){
    int n;
    cin>>n;
    ll mod=1e9+7LL;
    vi tab(n);
    input(tab);
    

    //1ere etape : on caclule le nb de i à n  àvaleurs < j tq il c'est (pas strictement) croissant

    ll nb[n+1][n+1];
    rep(i,0,n+1){
        nb[n][i]=1
    }
    for (int i=n-1;i>=0;i--){
        for (int j=0;j<n+1;j++){
            nb[i][j]=nb[i+1][j];
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    rep(i,0,t)
    solve();
}