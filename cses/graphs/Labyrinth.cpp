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

void dfs(int s, vi& path, vb& vu, int n, int m, vector<string>& tab){
    int lig=s/m;
    int col=s%m;
    if (col!=0){
        
    }   
}

void solve(){
    int n=get();
    int m=get();
    vector<string> tab(n);
    int start;
    int end;
    rep(i,0,n){
        string s;
        cin>>s;
        rep(j,0,m){
            if (s[j]=='A'){
                start=i*m+j;
                s[j]='.';
            }
            if (s[j]=='B'){
                end=i*m+j;
                s[j]='.';
            }
            tab[i]=s;
        }
    }
    // nb of cc
    vb vu(m*n);
    int tot=0;
    int i=start;
        int lig=i/m;
        int col=i%m;
        if (tab[lig][col]=='.' && !vu[i]){
            tot++;
            vu[i]=true;
            stack<int> q;
            q.push(i);
            while (!q.empty()){
                int s=q.top();
                if (s==end){

                }
                q.pop();
                lig=s/m;
                col=s%m;
                if (tab[lig][col]=='#') continue;
                if (lig!=0 && !vu[s-m]){
                    q.push(s-m);
                    vu[s-m]=true;
                }
                if (lig!=n-1 && !vu[s+m]){
                    q.push(s+m);
                    vu[s+m]=true;
                }
                if (col!=0 && !vu[s-1]){
                    vu[s-1]=true;
                    q.push(s-1);
                }
                if (col!=m-1 && !vu[s+1]){
                    vu[s+1]=true;
                    q.push(s+1);
                }
            }
        }
    
    cout<<tot<<'\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}