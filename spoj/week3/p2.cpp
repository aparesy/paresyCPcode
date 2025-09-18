#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define pdd pair<double,double>
#define vi vector<int>
#define vii vector<pii>
#define vvi vector<vector<int>>
#define ll long long
#define vl vector<ll>
#define vvl vector<vector<ll>>
#define vb vector<bool>
#define F first 
#define S second
#define rep(i,a,b) for(int i=a;i<b;i++)
#define input(tab) for (auto& x : tab)cin>>x

int dfs(int s, vb& vu1, vb& vu2, vvi& adj, vector<vi>& lab, vector<vii>& dp){
   // int tmp=0;
    for (auto t : adj[s]){
        if (!vu1[t]){
//            tmp++;
            vu1[t]=true;
            if (!vu2[t]){
                dfs(t,vu1,vu2,adj,lab,dp);
            }
            rep(i,0,26){
                dp[s][i].first += min(dp[t][i].second+1, dp[t][i].first);
                dp[s][i].second += min(dp[t][i].first+1, dp[t][i].second);
            }
        }
    }
    vu2[s]=true;
    return s;
}

void solve(){
    int n,l;
    cin>>n>>l;
    vvi adj(n);
    rep(i,0,n-1){
        int a,b;
        cin>>a>>b;
        a--;b--;
        adj[a].push_back(b); adj[b].push_back(a);
    }
    vector<vi> lab(n,vi(26));

    vb vu1(n);
    vb vu2(n);


    vector<vii> dp(n, vii(26));
    rep(i,0,l){
        int cur;
        string s;
        cin>>cur>>s;
        cur--;

        rep(i,0,26) dp[cur][i].second=10000000;

        if (s[0]!='$'){
            rep(j,0,s.length()){
                lab[cur][s[j]-'A']=true;
                dp[cur][s[j]-'A'].first=10000000;
                dp[cur][s[j]-'A'].second=0;
            }
        }
        vu2[cur]=true;
    }

    if (n==2){
        int tot=0;
        rep(i,0,26){
            tot+=lab[0][i]^lab[1][i];
        }
        cout<<tot;
        return;
    }
    int s;
    rep(i,0,n){
        if (!vu2[i]){
            vu1[i]=true;
            s=dfs(i,vu1,vu2,adj,lab,dp);
        }
    }   
    // rep(i,0,n){
    //     vu1[i]=false;
    // }
    // vu1[0]=true;
    // queue<int> q;
    // q.push(0);
    // while (!q.empty()){
    //     int s=q.front();
    //     q.pop();
    //     for (auto t: adj[s]){
    //         if (!vu1[t]){
    //             vu1[t]=true;
    //             rep(i,0,26){
    //                 if (lab[s][i]^lab[t][i]) tot++;
    //             }
    //             q.push(t);
    //         }
    //     }
    // }
    int tot=0;
    rep(i,0,26){
        tot+=min(dp[s][i].first, dp[s][i].second);
    }
    cout<<tot;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}