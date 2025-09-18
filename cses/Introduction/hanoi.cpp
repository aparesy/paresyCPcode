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
#define rep(i,a,b) for(int i=a;i<b;i++)

void hanoi(int n, int from, int to){
    if (n==1){
        cout<<from<<" "<<to<<"\n";
        return;
    }
    hanoi(n-1,from,6-from-to);
    cout<<from<<" "<<to<<"\n";
    hanoi(n-1,6-from-to,to);    
}

void solve(int n){
    ll tot=1;
    rep(i,0,n-1){
        tot=tot*2LL+1LL;
    }
    cout<<tot<<endl;
    hanoi(n,1,3);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    solve(n);
}