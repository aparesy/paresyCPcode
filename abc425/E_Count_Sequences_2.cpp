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
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define input(tab) for (auto& x : tab)cin>>x
#define all(x) x.begin(),x.end()

struct Congruence {
    long long a, m;
};



ll m;
vector<pair<ll,int>> decomposition; // pi puissance alphai
void decompose(){
    ll m2=m;
    while (m2>1){
        bool trouve=false;
        for (ll i=2;i*i<=m2 && !trouve;i++){
            if (m2%i==0){
                trouve=true;
                int alpha=0;
                while(m2%i==0){
                    alpha++;
                    m2/=i;
                }
                decomposition.push_back({i,alpha});
            }
        }
        if (!trouve){
            decomposition.push_back({m2,1});
            m2=1;
        }
    }
}

vvl fact;

void computefact(int ind){
    fact[ind].resize(5001);
    fact[ind][0]=1LL;
    ll mod=(ll)pow(decomposition[ind].first,decomposition[ind].second);
    rep(i,0,5000){
        fact[ind][i+1]=fact[ind][i]*(i+1LL);
        fact[ind][i+1]%=mod;
    }
}

ll computeInv(ll a, ll mod) {
    ll m0 = mod, t, q;
    ll x0 = 0, x1 = 1;
    if (mod == 1) return 0;
    while (a > 1LL) {
        q = a / mod;
        t = mod;
        mod = a % mod, a = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }
    if (x1 < 0LL) x1 += m0;
    return x1;
}

long long chinese_remainder_theorem(vector<Congruence> const& congruences) {
    long long M = 1;
    for (auto const& congruence : congruences) {
        M *= congruence.m;
    }

    long long solution = 0;
    for (auto const& congruence : congruences) {
        long long a_i = congruence.a;
        long long M_i = M / congruence.m;
        long long N_i = computeInv(M_i, congruence.m);
        solution = (solution + a_i * M_i % M * N_i) % M;
    }
    return solution;
}

ll get(){
   ll x;
   cin>>x;
   return x;
}

void solve(){
    ll n=get();
    vl tab(n);
    input(tab);
    ll tot=accumulate(all(tab),0LL);
    vector<Congruence> res;
    rep(i,0,decomposition.size()){
        //modulo pi puiss alpha i
        ll tmp=fact[i][tot];
        ll mod = (ll)pow(decomposition[i].first,decomposition[i].second);
        rep(j,0,n){
            ll denomWithPrime = fact[i][tab[j]];
            ll g;
            while ((g = gcd(denomWithPrime, mod)) > 1) {
                if (tmp % g != 0) {
                    tmp = 0;
                    break;
                }
                denomWithPrime /= g;
                tmp /= g;
            }
            if (tmp == 0) break;
            tmp *= computeInv(denomWithPrime, mod);
            tmp %= mod;
        }
        Congruence c = {tmp,mod};
        res.push_back(c);
    }
    cout<<chinese_remainder_theorem(res)<<"\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t=get();
    cin>>m;
    decompose();
    fact.resize(decomposition.size());
    rep(i,0,decomposition.size()) computefact(i);
    rep(i,0,t)
    solve();
}