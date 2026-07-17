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
mt19937 gen(time(0));

ll get(){
   ll x;
   cin>>x;
   return x;
}

void naive(){
    int n,m;
    cin>>n>>m;
    vl k(n);
    input(k);
    rep(i,0,m){
        ll a,b,c;
        cin>>a>>b>>c;
        bool ok=false;
        for (int i=0;i<n && !ok; i++){
            ll kCur=k[i];
            if (-kCur*b*2ll < -b*b+4ll*a*c){
                cout<<"YES\n"<<kCur<<"\n";
                ok=true;
            }
        }
        if (!ok){
            cout<<"NO\n";
        }
    }
    cout<<"\n";
}

void generator(){
    uniform_int_distribution<> dis(-20, 20);
    int t=dis(gen);
    while(t<0) t=dis(gen);
    cout<<t<<"\n";
    rep(i,0,t){
        int n=dis(gen);
    while(n<0) n=dis(gen);
        int m=dis(gen);
    while(m<0) m=dis(gen);
        cout<<n<<" "<<m<<"\n";
        rep(i,0,n){
            cout<<dis(gen)<<"\n";
        }
        rep(i,0,m){
                    int a=dis(gen);
    while(a<0) a=dis(gen); int b=dis(gen);int c=dis(gen);
            cout<<a<<" "<<b<<" "<<c<<"\n";
        }
    }
}

void solve(){
    int n,m;
    cin>>n>>m;
    set<ll> k;
    rep(i,0,n){
        ll x;
        cin>>x;
        k.insert(x);
    }
    rep(i,0,m){
        ll a,b,c;
        cin>>a>>b>>c;
        auto it=k.lower_bound(b);
        if (it!=k.end()){
            ll kCur=(*it);
            if ((b-kCur)*(b-kCur) >= 4ll*a*c && it!=k.begin()){
                it--;
                ll kCur=(*it);
                if ((b-kCur)*(b-kCur) < 4ll*a*c){
                    cout<<"YES\n"<<kCur<<"\n";
                }
                else{
                    cout<<"NO\n";
                }
            }
            else if ((b-kCur)*(b-kCur) < 4ll*a*c){
                cout<<"YES\n"<<kCur<<"\n";
            }
            else{
                cout<<"NO\n";
            }
        }
        else{
            it--;
            ll kCur=(*it);
            if ((b-kCur)*(b-kCur) < 4ll*a*c){
                cout<<"YES\n"<<kCur<<"\n";
            }
            else cout<<"NO\n";
        }
    }
    cout<<"\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); // generator(); return 0;
    int t; cin>>t; rep(i,0,t)
   // {cout<<"test case : "<<i+1<<"\n"; naive();}
    solve();
}