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

struct Node{
    ll g,l,r,s;
    Node operator+(const Node& a){
        return {max(max(a.g,g),a.r+l),
            max(a.l,a.s+l),
            max(r,s+a.r),
            a.s+s};
    }
};

struct Tree {
	typedef Node T;
	static constexpr T unit = {0,0,0,0};
	T f(T a, T b) { return a+b; } // (any associative fn)
	vector<T> s; int n;
	Tree(int n = 0, T def = unit) : s(2*n, def), n(n) {}
	void update(int pos, T val) {
		for (s[pos += n] = val; pos /= 2;)
			s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
	}
	T query(int b, int e) { // query [b, e)
		T ra = unit, rb = unit;
		for (b += n, e += n; b < e; b /= 2, e /= 2) {
			if (b % 2) ra = f(ra, s[b++]);
			if (e % 2) rb = f(s[--e], rb);
		}
		return f(ra, rb);
	}
};

void solve(){
    int n,m;
    cin>>n>>m;
    vl hotels(n);
    input(hotels);
    Tree t=Tree(n);
    rep(i,0,n){
        Node no={max(0ll,hotels[i]),hotels[i],hotels[i],hotels[i]};
        t.update(i,no);
    }
    rep(i,0,m){
        ll ind,x;
        cin>>ind>>x;
        t.update(ind-1,{max(0ll,x),x,x,x});
        cout<<t.query(0,n).g<<"\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}