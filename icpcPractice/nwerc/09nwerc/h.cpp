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

vector<int> catan(10001);

void solve(){
    catan[0]=1;
    vector<bool> ok(6,true);
    vector<int> count(6,0);
    count[1]++;
    rep(i,1,10001){
        ok.assign(6,true);
        

        ok[catan[i-1]]=false;
        rep(j,1,6){
            int minCount=INT_MAX;
            int minC=0;
            if (ok[j]&&count[j]<minCount){
                minCount=count[j];
                minC=j;
            }
            count[minC]++;
            catan[i]=minC;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}