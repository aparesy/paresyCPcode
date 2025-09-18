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

void solve(int a){
    // res = (res+a)*(b/c)
    // res = a*b/(c-b)
    int b,c;
    cin>>b>>c;
    int x=a*b;
    int y=c-b;
    int g=gcd(x,y);
    cout<<x/g<<"/"<<y/g<<"\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    while(cin>>n)
    solve(n);
}