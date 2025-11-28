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
#define sz(tab) tab.size()

/**
 * Author: Simon Lindholm
 * Date: 2015-03-15
 * License: CC0
 * Source: own work
 * Description: Self-explanatory methods for string hashing.
 * Status: stress-tested
 */

// Arithmetic mod 2^64-1. 2x slower than mod 2^64 and more
// code, but works on evil test data (e.g. Thue-Morse, where
// ABBA... and BAAB... of length 2^10 hash the same mod 2^64).
// "typedef ull H;" instead if you think test data is random,
// or work mod 10^9+7 if the Birthday paradox is not a problem.
typedef uint64_t ull;
struct H {
	ull x; H(ull x=0) : x(x) {}
	H operator+(H o) { return x + o.x + (x + o.x < x); }
	H operator-(H o) { return *this + ~o.x; }
	H operator*(H o) { auto m = (__uint128_t)x * o.x;
		return H((ull)m) + (ull)(m >> 64); }
	ull get() const { return x + !~x; }
	bool operator==(H o) const { return get() == o.get(); }
	bool operator<(H o) const { return get() < o.get(); }
};
static const H C = (ll)1e11+3; // (order ~ 3e9; random also ok)

struct HashInterval {
	vector<H> ha, pw;
	HashInterval(string& str) : ha(sz(str)+1), pw(ha) {
		pw[0] = 1;
		rep(i,0,sz(str))
			ha[i+1] = ha[i] * C + str[i],
			pw[i+1] = pw[i] * C;
	}
	H hashInterval(int a, int b) { // hash [a, b)
		return ha[b] - ha[a] * pw[b - a];
	}
};

vector<H> getHashes(string& str, int length) {
	if (sz(str) < length) return {};
	H h = 0, pw = 1;
	rep(i,0,length)
		h = h * C + str[i], pw = pw * C;
	vector<H> ret = {h};
	rep(i,length,sz(str)) {
		ret.push_back(h = h * C + str[i] - pw * str[i-length]);
	}
	return ret;
}

H hashString(string& s){H h{}; for(char c:s) h=h*C+c;return h;}

ll get(){
   ll x;
   cin>>x;
   return x;
}

ll fastExp(ll a, ll b, ll mod){
    ll cumul=1;
    while(b){
        if (b&1){
            cumul*=a;
            cumul%=mod;
        }
        a*=a;
        a%=mod;
        b>>=1;
    }
    return cumul%mod;
}

void solve(int m){
    string s;
    cin>>s;
    int n=s.length();

    ll mod=1e9+7ll;
    ll powPuiss=47ll;
    ll powPuiss2=79ll;
    vector<ll> hash(n);
    hash[0]=s[0];
    rep(i,1,n){
        hash[i]=hash[i-1];
        hash[i]*=powPuiss;
        hash[i]%=mod;
        hash[i]+=s[i];
        hash[i]%=mod;
    }
    vector<ll> hash2(n);
    hash2[0]=s[0];
    rep(i,1,n){
        hash2[i]=hash2[i-1];
        hash2[i]*=powPuiss2;
        hash2[i]%=mod;
        hash2[i]+=s[i];
        hash2[i]%=mod;
    }

    int r=n+1;
    int l=0;
    pii maxTot;
    while(r-l>1){
        int length=(l+r)/2;
        // Is it possible that a substring of length length appears m times
        pii maxi;
        map<H, pair<int,int>> cnt;
       rep(i,0,n-length+1){
            ll curHash1=hash[i+length-1];
            if (i) curHash1-=hash[i-1]*fastExp(powPuiss, length, mod);

            ll curHash2=hash2[i+length-1];
            if (i) curHash2-=hash2[i-1]*fastExp(powPuiss2, length, mod);
            curHash1=((curHash1%mod)+mod)%mod;
            curHash2=((curHash2%mod)+mod)%mod;

            ll curHash=(curHash1+curHash2)%mod;
            curHash+=mod;
            curHash%=mod; 

     //       vector<H> curHashes=getHashes(s,length);
       //     for (int i=0;i<curHashes.size();i++){
         //       auto curHash= curHashes[i];
                cnt[curHash].first++;
                cnt[curHash].second=i;
                if (cnt[curHash].first>=m){
                    maxi.first=cnt[curHash].first;
                    maxi.second=i;
                }
 //           }
        }
        if (maxi.first<m){
            r=length;
        }
        else{
            l=length;
            maxTot=maxi;
        }
    }
    if (l==0){
        cout<<"none\n";
    }
    else{
        // if (l==n-1) cout<<l<<" "<<0<<"\n";
        cout<<l<<" "<<maxTot.second<<"\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    while(cin>>t, t!=0){ 
    solve(t);
    }
}