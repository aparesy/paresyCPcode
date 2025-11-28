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
#define int ll

ll get(){
   ll x;
   cin>>x;
   return x;
}

//you want to assemble a letter with the shortest amount of time and optimize the resulting letter. Just do a dijkstra ? it mzight work somehow

vi lettres;
map<int,int> ordre;

bool comparator<(const string& a, const string& b){
    rep(i,0,min(a.length(), b.length()){
        if (a[i]==b[i]) continue;
        return ordre[a[i]] < ordre[b[i]];
    }
    if (a.length()==b.length()) return 0;
    else return (a.length()<b.length()?1:-1);
}

void solve(){
    int n=get();
    lettres.resize(n);
    ordre.clear();
    rep(i,0,n){
        string x;
        cin>>x;
        lettres[i]=x[0];
        ordre[x[0]]=i;
    }
    map<int, map<int, pair<int,int>>> fusion;
    rep(i,0,n){
        rep(j,0,n){
            string s;
            cin>>s;
            pair<int,int> tmp;
            tmp.first=stoi(string(s.substr(0,s.length()-2)));
            tmp.second=s[s.length()-1]; // directement une lettre
            fusion[lettres[i]][lettres[j]]=tmp; //idem
        }
    }
    int q=get();
    rep(i,0,q){
        string s;
        cin>>s;
        int k=s.length();
        priority_queue<pair<int,string>, vector<pair<int,string>>, greater<pair<int,string>>> q;
     //   map<string, bool> vu;
        rep(j,0,k-1){
            string s2=s;
            char c1=s[j];
            char c2=s[j+1];            
            s2.erase(j+1,1);
            pair<int,int> tmp = fusion[c1][c2];
            s2[j]=tmp.second;
            //vu[s2]=true; 
            q.push({tmp.first, s2});
        }
        while(!q.empty()){
            auto [t, tmpStr]=q.top();
            q.pop();
            if (tmpStr.length()==1){
                cout<<t<<'-'<<tmpStr<<"\n";
                break;
            }
            else{
                rep(j,0,tmpStr.length()-1){
                    string s2=tmpStr;
                    char c1=tmpStr[j];
                    char c2=tmpStr[j+1];            
                    pair<int,int> tmp = fusion[c1][c2];
                    s2.erase(j+1);
                    s2[j]=tmp.second;
                 //   vu[s2]=true; 
                    q.push({t+tmp.first, s2});
                }
            }
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    #ifdef DEBUG
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    #endif
    cin.tie(0);
    solve();
    int x;
    cin>>x;
}