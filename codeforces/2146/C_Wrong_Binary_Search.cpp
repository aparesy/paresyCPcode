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

void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    if (s[0]=='0'&&s[1]=='1'){
        cout<<"NO\n";
        return;
    }
    if (s[n-2]=='1'&&s[n-1]=='0'){
        cout<<"NO\n";
        return;
    }
    rep(i,1,n-1){
        if (s[i-1]=='1'&&s[i]=='0'&&s[i+1]=='1'){
            cout<<"NO\n";
        return;
        }
    }

    cout<<"YES\n";
    int debut=1;
    rep(i,0,n){
        if (s[i]=='1'){
            cout<<i+1<<" ";
            debut=i+2;
        }
        else{
            if (i==n-1 || s[i+1]=='1'){
                cout<<debut<<" ";
            }
            else cout<<i+2<<" ";
        }
    }
    cout<<"\n";
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    rep(i,0,t)
    solve();
}