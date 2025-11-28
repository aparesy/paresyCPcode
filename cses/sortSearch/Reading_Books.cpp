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

void solve(){
    int n;
    cin>>n;
    vl tab(n);
    input(tab);
    // Book reading. Idea : go in decreasing order, and for each book, try increasing order? 
    // The paths will cross, so probably incorrect. What we can do though( good heuristic) is togo back to last. Then, guarantee
    sort(all(tab));
    int i=0;
    ll tot=0;
    while (tot<tab[n-1] && i<n-1){
        tot+=tab[i];
        i++;
    }
    if (i!=n-1 || tot>=tab[n-1]){
        cout<<accumulate(all(tab),0LL);
    }
    else{
        cout<<accumulate(all(tab),0LL)+tab[n-1]-tot;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}