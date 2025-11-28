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
    
    string s; // Rabbit, plant (1) (change with a zero if covered)
    cin>>s;
    if (n==1){
        cout<<"YES\n";
        return;
    }

    if (s[0]=='0' && s[1]=='1'){
        s[1]='3';
    }
    int i=1;
    while (i<n-1){
        if (s[i]=='0'){
            if (s[i-1]=='0'){
                if (s[i+1]=='1') s[i+1]='3'; // CAN be covered
            }
            else if (s[i-1]=='1'){
                if (s[i+1]=='1'){
                    s[i+1]='2'; // HAS to be covered
                    if (i==n-2 || s[i+2]=='1'){
                        cout<<"NO\n";
                        return;
                    }
                }
            }
            else if (s[i-1]=='3'){
                if (s[i+1]=='1') s[i+1]='3';
            }
        }
        i++;
    }
    cout<<"YES\n";
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