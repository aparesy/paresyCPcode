// Useful functions : nth_element, rotate, unique, merge, count, generate

#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define pdd pair<double,double>
#define vi vector<int>
#define vii vector<pii>
#define vvi vector<vector<int>>
using ll=long long;
#define vl vector<ll>
#define vvl vector<vector<ll>>
#define vb vector<bool>
#define F first 
#define S second
#define rep(i,a,b) for(int i=a;i<b;i++)
#define input(tab) for (auto& x : tab)cin>>x
#define all(x) x.begin(),x.end()

ll get(){
   ll x;
   cin>>x;
   return x;
}

bool quesDesA(string s){
    for (int i=0;i<s.length();i++){
        if (s[i]!='a') return false;
    }
    return true;
}

ll nombreAs(string s){
    int tot=0;
    rep(i,0,s.length()){
        tot++;
    }
    return tot;
}

void solve(){
    int n;
    cin>>n;
    bool onlyAs=true; // in t
    pair<ll,ll> nbAs={1,1};
    pair<ll,ll> longueurs={1,1};
    bool OnlyAsinA=true;
    rep(i,0,n){
        int d;
        cin>>d;
        if (d==1){
            ll k;
            cin>>k;
            string s;
            cin>>s;
            if (!quesDesA(s)){
                OnlyAsinA=false;
            }
            longueurs.first+=((ll)s.length())*(k);
        }
        else{
            ll k;
            cin>>k;
            string s;
            cin>>s;
            if (!quesDesA(s)){
                onlyAs=false;
            }
            nbAs.second+=(s.length())*k;
            longueurs.second+=((ll)s.length())*(k);
        }
        if (!onlyAs){
            cout<<"YES\n";
        }
        else if (OnlyAsinA && longueurs.first<longueurs.second){
            cout<<"YES\n";
        }
        else cout<<"NO\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin>>t; rep(i,0,t)
    solve();
}