#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define forn(i,n) for(int i=0;i<n;i++)
 
void comb(vector<int>& acc, int x, int cur, int n){
    if (cur==n-1){
        acc.push_back(x);
        return;
    }
    if ((x & (1<<cur)) && (x & (1<<(cur+1)))){
        x^=(1<<cur);
        x^=(1<<(cur+1));
        comb(acc,x,cur+1,n);
        x^=(1<<cur);
        x^=(1<<(cur+1));
    }
    comb(acc,x,cur+1,n);
}
 
bool valid(int i, int n){
    forn(j,n){
        if (!(i & (1<<j))){
            if (i & (1<<(j+1))){
                return false;
            }
            if (j==n-1) return false;
            j++;
        }
    }
    return true;
}
 
signed main(){
    int n,m;
    int mod=1e9+7ll;
    cin>>n>>m;
    if (m==1){
        cout<<((n%2)==0)<<"\n";
        return 0;
    }
    int dp[1001][2001];
    forn(i,m){forn(j,1<<n){dp[i][j]=0;}}
    // forn(i,1<<n){
    //     if(valid(~i,n)) dp[0][i]=1;
    // }
    dp[0][0]=1;
    forn(i,m-1){
        forn(j,1<<n){
            int k=((1<<n)-1)^j;
            vector<int> acc;
            comb(acc,k,0,n);
            for(auto l : acc){
                //cout<<i<<" "<<j<<" "<<l<<"\n";
                dp[i+1][l]+=dp[i][j];
                if (dp[i+1][l]>=mod) dp[i+1][l]-=mod;
            }
        }
    }
    int tot=0;
    forn(i,1<<n){
        if (valid(i,n)) tot+=dp[m-1][i];
        if (tot>=mod) tot-=mod;
    }
    // tot=dp[m-1][(1<<n)-1];
    cout<<tot;
}