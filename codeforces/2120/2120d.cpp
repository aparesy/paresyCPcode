#include <bits/stdc++.h>

using namespace std;
#define ll unsigned long long
#define vi vector<int>
#define vl vector <ll>
vector<int> read_ints(int n) { vector<int> v(n); for (auto& x : v) cin >> x; return v; }
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define loop(n) for(int i=0;i<n;i++)

ll inv(ll a, ll m) {
  return a <= 1 ? a : m - (long long)(m/a) * inv(m % a, m) % m;
}

int main(){
    int t;
    cin >> t;
    ll MOD=1;
    for (int i=0;i<9;i++){
        MOD*=10LL;
    }
    MOD+=7LL;
    while (t--){
        ll a,b,k;
        cin>>a>>b>>k;
        ll n=k*(a-1LL)+1LL;
        ll parmi=1LL; // a parmi n
        for (ll i=n;i>n-a;i--){
            parmi*=i;
            parmi%=MOD;
        }
        for (ll i=1;i<=a;i++){
       //     cout<<i<<" "<< inv(i,MOD)<< " "<< (inv(i,MOD)*i)%MOD<<endl;
            parmi*=inv(i,MOD);
            parmi%=MOD;
        }
        ll tmp=(k*parmi+MOD)%MOD;
        cout<<(n+MOD)%MOD<<" "<<(tmp*(b-1LL)+1LL+MOD)%MOD<<endl;
    }
}