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

vi prime(10000,-1);

void computePrime(){
    prime[0]=0;
    prime[1]=1;
    for (int i=2;i*i<10000;i++){
        if (prime[i]==-1){
            for (int j=i*i;j<10000;j+=i){
                prime[j]=i;
            }
        }
    }
}

int replaceDigit(int i,int j,int pos){
    int tmp=i;
    for (int k=0;k<pos;k++){
        tmp/=10;
    }
    tmp-=(tmp%10);
    tmp+=j;
    for (int k=0;k<pos;k++){
        tmp*=10;
    }
    tmp+=(i%((int)pow(10,pos)));
    return tmp;
}

void solve(){
    vvi adj(10000);
    for (int i=1000;i<10000;i++){
        if (prime[i]==-1){
            for (int j=0;j<10;j++){
                for (int pos=0;pos<4;pos++){
                    if (!(pos==3 &&j==0) && prime[replaceDigit(i,j,pos)]==-1){
                        adj[i].push_back(replaceDigit(i,j,pos));
                    }
                }
            }
        }
    }

    vi cost(10000,-1);
    int a,b;
    cin>>a>>b;
    cost[a]=0;
    priority_queue<pii,vii,greater<pair<int,int>>> q;
    q.push({0,a});
    while (cost[b]==-1 && !q.empty()){
        auto s=q.top();
        q.pop();
        for (auto t : adj[s.second]){
            if (cost[t]==-1 || cost[t]>cost[s.second]+1){
                cost[t]=cost[s.second]+1;
                q.push({cost[s.second]+1,t});
            }
        }
    }
    if (cost[b]==-1){
        cout<<"IMPOSSIBLE\n";
    }
    else{
        cout<<cost[b]<<"\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    computePrime();
   // rep(i,1,1000) cout<<prime[i]<<" ";
   // cout<<replaceDigit(1999,5,2);
 //  cout<<replaceDigit(1999,5,3);
  //  cout<<replaceDigit(1999,4,0);
    int t;
    cin>>t;
    rep(i,0,t)
    solve();
}