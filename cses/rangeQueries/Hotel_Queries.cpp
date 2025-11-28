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


struct Tree {
	typedef int T;
	static constexpr T unit = INT_MIN;
	T f(T a, T b) { return max(a, b); } // (any associative fn)
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
    int query2(int seuil){
        int l=0; int r=n;
        while(r-l>1){
            int m=(l+r)/2;
            if (query(l,m)>=seuil){
                r=m;
            }
            else l=m;
        }
        return l;
    }
};

void solve(){
    int n,m;
    cin>>n>>m;
    vl hotels(n);
    input(hotels);
    vl people(m);
    input(people);
    //update : reduce a hotel
    // query : ? find the lowest indiced hotel st capacity >= p
    // simply done with a mintree, always go left in priority
    Tree t=Tree(n);
    rep(i,0,n){
        t.update(i,hotels[i]);
    }
    rep(i,0,m){
        int ind=t.query2(people[i]);
        if (hotels[ind]<people[i]){
            cout<<0<<" ";
        }
        else{
            cout<<ind+1<<" ";
            hotels[ind]-=people[i];
            t.update(ind,hotels[ind]);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}