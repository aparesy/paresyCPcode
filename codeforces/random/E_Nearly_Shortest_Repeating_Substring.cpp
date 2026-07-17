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

ll mod1=1e9+7ll;
ll mod2=998976589ll;

ll hashMult1 = 697;
ll hashMult2 = 52079;

ll fastExp(ll a, ll b, ll mod){
    ll cumul=1;
    while (b){
        if (b&1){
            cumul*=a;
            cumul%=mod;
        }
        a*=a;
        a%=mod;
        b>>=1;
    }
    return cumul;
}

void solve(){

    int n=get();
    string s;
    cin>>s;

    vl hash1(n);
    vl hash2(n);
    rep(i,0,n){
        hash1[i]=(i==0?0:hash1[i-1]);
        hash1[i]*= hashMult1;
        hash1[i]+=s[i];
        hash1[i]%=mod1;
    }
    ll invHash1Mult=fastExp(hashMult1,mod1-2ll,mod1);
    rep(i,1,n/2+1){
        if (n%i==0){
            map<ll,pair<int,int>> cnt;
            ll bonnePuissHash=fastExp(hashMult1,i,mod1);
            for (int k=0;k<n && cnt.size()<=2 ;k+=i){
                if (k==0){
                    cnt[hash1[i-1]].first++;
                    cnt[hash1[i-1]].second=k;
                }
                else{
                    ll tmp=(hash1[k-1]*bonnePuissHash)%mod1;
                    ll tmpHash=hash1[k+i-1]-tmp;
                    tmpHash= ((tmpHash%mod1)+mod1) % mod1;
         //           tmpHash*=fastExp(invHash1Mult,k+i,mod1);
                    cnt[tmpHash].first++;
                    cnt[tmpHash].second=k;
                }
            }
            if (cnt.size()>2){
                continue;
            }
            else{
                bool trouve=false;
                int ind=0;
                if (cnt.size()==1){
                    cout<<i<<"\n";
                    return;
                }
                for(auto [key, value] : cnt){ if (value.first==1) trouve=true; ind=value.second;}
                if (trouve){
                    trouve=false;
                    bool ok=true;
                    int ind2=((ind==0)?(ind+i):(ind-i));
                    rep(j,0,i){
                        if (s[j+ind]!=s[j+ind2]){
                            if (trouve==true) ok=false;
                            else trouve=true;
                        }
                    }
                    if (ok){
                        cout<<i<<"\n";
                        return;
                    }
                }
            }
        }
    }
    cout<<n<<"\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin>>t; rep(i,0,t)
    solve();
}