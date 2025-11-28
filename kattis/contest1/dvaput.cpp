// Useful functions : nth_element, rotate, unique, merge, count, generate

#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define pdd pair<double,double>
#define vi vector<int>
#define vii vector<pii>
#define vvi vector<vector<int>>
using ll=unsigned long long;
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

void solve(){
    string s;
    cin>>s;
    int n=s.length();
    int l=0;
    int r=n;
    int a,b;
  //  ll mod=((ll)1e9+7ll);
    while(r-l>1){
        int m=(r+l)/2;
        // Find if there are two strings of length m
        bool ok=false;
        unordered_map<ll,int> trouve;
        ll hash=0;
        ll tmp=1;
        rep(i,0,m){
            hash*=911ll;
            hash+=((ll)(s[i]-'a'+1));
 //           hash%=mod;
        }
        trouve[hash]=0;
        rep(i,0,m-1){
            tmp*=911ll;
 //           tmp%=mod;
        }
        rep(i,0,n-m){
            hash = (911LL * (hash - tmp * (s[i]-'a'+1))  + (s[i+m]-'a'+1)) ;
            if (trouve.count(hash)){
                a=trouve[hash];b=i+1;
                ok=true;
                break;
            }
            trouve[hash]=i+1;
        }
        if (!ok){
            r=m;
        }
        else l=m;
    }
    if (l==0)cout<<-1<<"\n";
    else{
        rep(i,0,l){
            cout<<s[a+i];
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}