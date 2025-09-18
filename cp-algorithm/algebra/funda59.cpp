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

void solve(){
    vector<ll> fib;
    fib.push_back(0LL);
    fib.push_back(1LL);
    while(fib.back()<1e13){
        fib.push_back(fib.back()+fib[fib.size()-2]);
        cout<<fib.back()<<endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}