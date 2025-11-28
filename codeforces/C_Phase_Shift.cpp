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

void solve(){
    int n=get();
    string s;
    cin>>s;
    vector<char> shift(26);
    vector<char> invShift(26);
    int shiftCnt=0;
    rep(i,0,n){
        int cur=s[i]-'a';
        if (shift[cur]){
            cout<<(shift[cur]);
        }
        else{
            if (shiftCnt==25){
                rep(j,0,26){
                    char tmp='a'+j;
                    if (!invShift[j]){
                        invShift[j]=cur;
                        shift[cur]=tmp;
                    }
                }
            }
            else{
                bool ok=false;
                for (int j=0;j<26 && !ok; j++){
                    char tmp='a'+j;
                    // Si on ne complète pas un cycle en ajoutant tmp comme shift de s[i]
                    if (cur != j && !invShift[j]){
                        char tmp2=s[i];
                        while (invShift[tmp2-'a']) tmp2=invShift[tmp2-'a'];
                        if (tmp2 == tmp) continue;

                        invShift[j]=cur+'a';
                        shift[cur]=tmp;
                        ok=true;
                        shiftCnt++;
                    }
                }
            }
            cout<<shift[cur];
        }
    }
    cout<<"\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin>>t; rep(i,0,t)
    solve();
}