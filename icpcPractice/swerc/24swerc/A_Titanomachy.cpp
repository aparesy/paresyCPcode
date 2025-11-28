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

ll get(){
   ll x;
   cin>>x;
   return x;
}

/**
 * Author: Simon Lindholm
 * Date: 2015-09-12
 * License: CC0
 * Source: me
 * Description: When you need to dynamically allocate many objects and don't care about freeing them.
 * "new X" otherwise has an overhead of something like 0.05us + 16 bytes per allocation.
 * Status: tested
 */

// Either globally or in a single class:
static char buf[450 << 20];
void* operator new(size_t s) {
	static size_t i = sizeof buf;
	assert(s < i);
	return (void*)&buf[i -= s];
}
void operator delete(void*) {}

struct Node2{
    ll g,l,r,s;
};
ll totS;


Node2 f(Node2 a, Node2 b) { return {max(max(a.g,b.g),a.r+b.l+totS), max(a.l,a.s+b.l+totS), max(b.r,b.s+a.r+totS), a.s+b.s+totS}; } // (any associative fn)


/**
 * Author: Simon Lindholm
 * Date: 2016-10-08
 * License: CC0
 * Source: me
 * Description: Segment tree with ability to add or set values of large intervals, and compute max of intervals.
 * Can be changed to other things.
 * Use with a bump allocator for better performance, and SmallPtr or implicit indices to save memory.
 * Time: O(\log N).
 * Usage: Node* tr = new Node(v, 0, sz(v));
 * Status: stress-tested a bit
 */

const int inf = 1e9;
struct Node {
	Node *l = 0, *r = 0;
	int lo, hi; int mset = inf, madd = 0;
    Node2 val={0,0,0,0};
	Node(int lo,int hi):lo(lo),hi(hi){} // Large interval of -inf
	Node(vector<Node2>& v, int lo, int hi) : lo(lo), hi(hi) {
		if (lo + 1 < hi) {
			int mid = lo + (hi - lo)/2;
			l = new Node(v, lo, mid); r = new Node(v, mid, hi);
			val = f(l->val, r->val);
		}
		else val = v[lo];
	}
	Node2 query(int L, int R) {
		if (R <= lo || hi <= L) return {-inf,0ll,0ll,0ll};
		if (L <= lo && hi <= R) return val;
		push();
		return f(l->query(L, R), r->query(L, R));
	}
	void set(int L, int R, ll x) {
		if (R <= lo || hi <= L) return;
		if (L <= lo && hi <= R) mset = val.g=val.l=val.r=val.s = x, madd = 0;
		else {
			push(), l->set(L, R, x), r->set(L, R, x);
			val = f(l->val, r->val);
		}
	}
	void add(int L, int R, int x) {
		if (R <= lo || hi <= L) return;
		if (L <= lo && hi <= R) {
			if (mset != inf) mset += x;
			else madd += x;
            val.g+=x;
		}
		else {
			push(), l->add(L, R, x), r->add(L, R, x);
			val = f(l->val, r->val);
		}
	}
	void push() {
		if (!l) {
			int mid = lo + (hi - lo)/2;
			l = new Node(lo, mid); r = new Node(mid, hi);
		}
		if (mset != inf)
			l->set(lo,hi,mset), r->set(lo,hi,mset), mset= inf;
		else if (madd)
			l->add(lo,hi,madd), r->add(lo,hi,madd), madd=0;
	}
};

void solve(){
    int n,q;
    totS=0;
    cin>>n>>q;
    Node2 def={0,0,0,0};
    vector<Node2> v(n,def);
    Node* t = new Node(v, 0, sz(v));
    rep(i,0,n){
        ll x;
        cin>>x;
        t->set(i,i+1,x);
    }
    rep(i,0,q){
        string s;
        cin>>s;
        if (s[0]=='A'){
            int l,r;
            cin>>l>>r;
            l--;r--;
            Node2 tmp=t->query(l,r+1);
            if (tmp.g>0){
                cout<<tmp.g<<"\n";
            }
            else cout<<0<<"\n";
        }
        else{
            ll x;
            cin>>x;
            totS+=x;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}