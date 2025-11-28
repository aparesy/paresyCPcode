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
    int n,k;
    cin>>n>>k;
    string s,t;
    cin>>s>>t;
    vi dist(n);
    int j=n-1;
    int i=n-1;
    while(j>=0){
        while(i>=0 && s[i]!=t[j]) i--;
        if (i<0){
            cout<<-1<<"\n";
            return;
        }
        dist[j]=j-i;
        if (dist[j]>k){
            cout<<-1<<"\n";
            return;
        }
        if (i==j) i--;
        j--;
    }
    int me=(*max_element(all(dist)));
    cout<<me<<"\n";
    rep(l, 0, me){
        int curDist=0;
        for (int m=n-1; m>=0; m--){
            // On parcourt notre chaine
            curDist=max(curDist, dist[m]);
            if (curDist){
                s[m]=s[m-1];
            }
            if (dist[m]) dist[m]--;
            curDist--;
        }
        cout<<s<<"\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin>>t; rep(i,0,t)
    solve();
}