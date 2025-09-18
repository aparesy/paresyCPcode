#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define pdd pair<double,double>
#define vi vector<int>
#define vii vector<pii>
#define vvi vector<vector<int>>
#define ll long long
#define vl vector<ll>
#define rep(i,a,b) for(int i=a;i<b;i++)

void solve(){
    int n;
    cin>>n;
    vi ranking(n);
    for(auto& x: ranking)cin>>x;

    vi invRanking(n+1);
    rep(i,0,n){
        invRanking[ranking[i]]=i;
    }

    int m; cin>>m;
    vii pairs;
    rep(i,0,m){
        int a,b;
        cin>>a>>b;
        if (invRanking[a]>invRanking[b]) swap(a,b);
        pairs.push_back({a,b});
    }
    sort(pairs.begin(), pairs.end(), [&invRanking](auto& a, auto& b){if (a.first==b.first) 
                                                    return invRanking[a.second]>invRanking[b.second]; return invRanking[a.first]>invRanking[b.first];});
    // On process toutes les paires
    int i=0;
    while (!pairs.empty() && i<n-1){
        int a,b;
        tie(a,b)=pairs[pairs.size()-1];
        pairs.erase(pairs.end()-1);
        i=invRanking[a];
        if (i==n-1 || ranking[i+1]!=b){
            cout<<"IMPOSSIBLE\n";
            return;
        }
        swap(ranking[i], ranking[i+1]);
        swap(invRanking[a], invRanking[b]);
    }
    for (auto x :ranking)cout<<x<<" ";
    cout<<"\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    rep(i,0,t)
    solve();
}