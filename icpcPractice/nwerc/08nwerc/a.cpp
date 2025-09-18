#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pii>
#define ll long long
#define vl vector<ll>
#define rep(i,a,b) for(int i=a;i<b;i++)

void traiterArbre(string s, vl& sommetDepth){
    int depth=0;
    bool chiffre=(s[0]>='0'&&s[0]<='9');
    ll curChiffre=0LL;
    rep(i,0,s.length()){
        if (chiffre){
            if (s[i]==']'){
                sommetDepth.push_back(curChiffre*(1<<depth));
                chiffre=false;
                depth--;
            }
            else if (s[i]==','){
                sommetDepth.push_back(curChiffre*(1<<depth));
                chiffre=false;
            }
            else{
                curChiffre*=10LL;
                curChiffre+=(ll)(s[i]-'0');
            }
        }
        else{
            if (s[i]=='['){
                depth++;
            }
            else if (s[i]==']'){
                depth--;
            }
            else if (s[i]==','){}
            else{
                chiffre=true;
                curChiffre=(ll)(s[i]-'0');
            }
        }
    }
    if (chiffre) sommetDepth.push_back(curChiffre*(1<<depth));
}

void solve(){
    string s;
    cin>>s;
    vl sommetDepth;
    traiterArbre(s,sommetDepth);
//    for (auto x : sommetDepth) cout<<x<<" ";
    sort(sommetDepth.begin(),sommetDepth.end());
    int maxOcc=1;
    int curMax=1;
    rep(i,1,sommetDepth.size()){
        if (sommetDepth[i]==sommetDepth[i-1]){
            curMax++;
        }
        else{
            maxOcc=max(maxOcc, curMax);
            curMax=1;
        }
    }
    maxOcc=max(maxOcc, curMax);
    cout<<sommetDepth.size()-maxOcc<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    rep(i,0,t)
    solve();
}