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
 * Author: Unknown
 * Date: 2002-09-13
 * Source: predates tinyKACTL
 * Description: Topological sorting. Given is an oriented graph.
 * Output is an ordering of vertices, such that there are edges only from left to right.
 * If there are cycles, the returned list will have size smaller than $n$ -- nodes reachable
 * from cycles will not be returned.
 * Time: $O(|V|+|E|)$
 * Status: stress-tested
 */
#pragma once

vi topoSort(const vector<vi>& gr) {
	vi indeg(sz(gr)), q;
	for (auto& li : gr) for (int x : li) indeg[x]++;
	rep(i,0,sz(gr)) if (indeg[i] == 0) q.push_back(i);
	rep(j,0,sz(q)) for (int x : gr[q[j]])
		if (--indeg[x] == 0) q.push_back(x);
	return q;
}

void solve(){
    int n;
    cin>>n;
    vvi adj(n);
    rep(i,0,n){
        int c;
        cin>>c;
        rep(j,0,c){
            int x;
            cin>>x;
            adj[i].push_back(x-1);
        }
    }

    // now toposort
    vi sorted=topoSort(adj);
    vi invSorted(n);
    rep(i,0,n){
        invSorted[sorted[i]]=i;
    }
    vi dp(n);
    dp[0]=1;
    rep(i,0,n){
        for (auto t : adj[sorted[i]]){
            dp[invSorted[t]]=max(dp[invSorted[t]],dp[i]+1);
        }
    }
    cout<<((*max_element(all(dp)))==n);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}