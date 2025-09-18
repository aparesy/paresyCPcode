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

ll nfact(int n){
    if (n==1) return 1;
    return n*nfact(n-1);
}


void solve(){
    int n;
    cin>>n;
    vector<string> tab(n);
    input(tab);
    vector<char> lettres;
    for (auto s : tab){
        for (int i=0;i<s.length();i++){
            bool ok=true;
            for (auto c : lettres){
                if (c==s[i]){
                    ok=false;
                }
            }
            if (ok) lettres.push_back(s[i]);
        }
    }
    vector<int> lettreToNb(26);
    for (int i=0;i<26;i++){
        for (int j=0;j<lettres.size();j++){
            if (lettres[j]=='A'+i){
                lettreToNb[i]=j;    
            }
        }
    }
    vi combi(10);
    for (int i=0;i<10;i++){
        combi[i]=i;
    }
    int tot=0;
    do{
        bool ok=true;
        int tmp=0;
        string scur;
        for (int i=0;i<10&&(tab[n-1].length()>=i);i++){
            for (int j=0;j<n-1;j++){
                scur=tab[j];
                if (scur.length()>i){
                    tmp+=combi[lettreToNb[(int)(scur[scur.length()-i-1]-'A')]];
                }
            }
            scur=tab[n-1];
            if (i==tab[n-1].length()){
                if (tmp){
                ok=false;
                break;
                }
            }
            else if ((i!=tab[n-1].length()) && (tmp%10) != combi[lettreToNb[(int)(scur[scur.length()-i-1]-'A')]]){
                ok=false;
                break;
            }

            tmp=tmp/10;
        }
        if (ok){
            tot++;
            rep(i,0,nfact(10-lettres.size())) next_permutation(combi.begin(),combi.end());
        }
    }
    while(next_permutation(combi.begin(),combi.end()));
    cout<<tot;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}