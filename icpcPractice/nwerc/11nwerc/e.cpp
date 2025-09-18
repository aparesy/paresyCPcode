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
    int n;
    cin>>n;
    ll total=0;
    string s;
    cin>>s;

    unordered_map<char,int> compte;
    for (auto c: s)compte[c]++;

    unordered_map<char,bool> vu;
    unordered_map<char,bool> vuDef;

    int lastBienPlace=n-1;
    while (lastBienPlace>0){
        char reference=s[lastBienPlace];
        int cur=lastBienPlace-1;
        vu.clear();
        while (cur>=0){
            while(cur>=0&&s[cur]!=reference)cur--;
            if (cur>=0){
                while (cur!=lastBienPlace-1){
                    char tmp=s[cur];
                    s[cur]=s[cur+1];
                    s[cur+1]=tmp;
                    cur++;
                    if (!vu[s[cur-1]]&&!vuDef[s[cur-1]]) total+=5LL*compte[s[cur-1]];
                    vu[s[cur-1]]=true;
                }
                cur--;
                lastBienPlace--;
            }
            cur--;
        }
        vu[s[lastBienPlace]]=true;
        lastBienPlace--;
    }
    cout<<total<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    rep(i,0,t)
    solve();
}