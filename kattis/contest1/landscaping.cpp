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
#define 

ll get(){
   ll x;
   cin>>x;
   return x;
}

/**
 * Author: Stanford
 * Date: Unknown
 * Source: Stanford Notebook
 * Description: Min-cost max-flow.
 *  If costs can be negative, call setpi before maxflow, but note that negative cost cycles are not supported.
 *  To obtain the actual flow, look at positive values only.
 * Status: Tested on kattis:mincostmaxflow, stress-tested against another implementation
 * Time: $O(F E \log(V))$ where F is max flow. $O(VE)$ for setpi.
 */
#pragma once

// #include <bits/extc++.h> /// include-line, keep-include


pair<int, vi> globalMinCut(vector<vi> mat) {
	pair<int, vi> best = {INT_MAX, {}};
	int n = sz(mat);
	vector<vi> co(n);
	rep(i,0,n) co[i] = {i};
	rep(ph,1,n) {
		vi w = mat[0];
		size_t s = 0, t = 0;
		rep(it,0,n-ph) { // O(V^2) -> O(E log V) with prio. queue
			w[t] = INT_MIN;
			s = t, t = max_element(all(w)) - w.begin();
			rep(i,0,n) w[i] += mat[t][i];
		}
		best = min(best, {w[t] - mat[t][t], co[t]});
		co[s].insert(co[s].end(), all(co[t]));
		rep(i,0,n) mat[s][i] += mat[t][i];
		rep(i,0,n) mat[i][s] = mat[s][i];
		mat[0][t] = INT_MIN;
	}
	return best;
}

void solve(){
    int n,m;
    cin>>n>>m;
    int a,b;
    cin>>a>>b;
    vvi grid(n,vi(m));
    rep(i,0,n){
        string s;
        cin>>s;
        rep(j,0,m){
            grid[i][j]=(s[j]=='#');
        }
    }
    vvi g(2*n*m+2*(n+m)+2);
    rep(i,0,n-1){
        rep(j,0,m-1){
            g.addEdge(i*m+j,i*m+j+1,1,(grid[i][j]!=grid[i][j+1])*a+(grid[i][j+1]==1)*b);
            g.addEdge(i*m+j,(i+1)*m+j,1, (grid[i][j]!=grid[i+1][j])*a+(grid[i+1][j]==1)*b);
            g.addEdge(i*m+j,n*m+i*m+j+1,1,(grid[i][j]==grid[i][j+1])*a+(grid[i][j+1]==0)*b);
            g.addEdge(i*m+j,n*m+(i+1)*m+j,1, (grid[i][j]==grid[i+1][j])*a+(grid[i+1][j]==0)*b);

            g.addEdge(n*m+i*m+j,i*m+j+1,1,(grid[i][j]==grid[i][j+1])*a+(grid[i][j+1]==1)*b);
            g.addEdge(n*m+i*m+j,(i+1)*m+j,1, (grid[i][j]==grid[i+1][j])*a+(grid[i+1][j]==1)*b);
            g.addEdge(n*m+i*m+j,n*m+i*m+j+1,1,(grid[i][j]!=grid[i][j+1])*a+(grid[i][j+1]==0)*b);
            g.addEdge(n*m+i*m+j,n*m+(i+1)*m+j,1, (grid[i][j]!=grid[i+1][j])*a+(grid[i+1][j]==0)*b);
        }
    }
    rep(i,0,n){
        g.addEdge(2*n*m+2*(n+m),2*n*m+i,1,0);
        g.addEdge(2*n*m+i,i*m,1,(grid[i][0]==1)*b);
        g.addEdge(2*n*m+i,i*m+n*m,1,(grid[i][0]==0)*b);
    }
    rep(i,0,n){
        g.addEdge(2*n*m+n+i,2*n*m+2*(n+m)+1,1,0);
        g.addEdge(i*m+m-1,2*n*m+i+n+1,1,0);
        g.addEdge(i*m+m-1+m*n,2*n*m+i+n+1,1,0);
    }
    rep(j,0,m){
        g.addEdge(2*n*m+2*(n+m),2*n*m+2*n+j,1,0);
        g.addEdge(2*n*m+2*n+j,j,1,(grid[0][j]==1)*b);
        g.addEdge(2*n*m+2*n+j,j+n*m,1,(grid[0][j]==0)*b);
    }
    rep(j,0,m){
        g.addEdge(2*n*m+2*n+m+j,2*n*m+2*(n+m)+1,1,0);
        g.addEdge((n-1)*m+j,2*n*m+2*n+m+j,1,0);
        g.addEdge((n-1)*m+j+m*n,2*n*m+2*n+m+j,1,0);
    }
    cout<<g.maxflow(2*n*m+2*(n+m),2*n*m+2*(n+m)+1).second<<"\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin>>t; rep(i,0,t)
    solve();
}