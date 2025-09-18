#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>

const int NMAX= 3*1e5;
ll fact[NMAX];

void remplirFact(ll mod){
    fact[0]=1LL;
    for (int i=1;i<NMAX;i++){
        fact[i]=((fact[i-1]*i)%mod);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    ll mod=1e9+7;
    remplirFact(mod);
    while(t--){
        ll n;
        cin>>n;
        ll m;
        cin>>m;
        ll tot=2;
        bool ok=true;
        vector<int> vu(n+1);
        vector<vector<int>> adj(n+1);
        for (int i=0;i<m;i++){
            int a,b;
            cin>>a>>b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        vu[0]=1;
        vu[1]=1;
        queue<int> q;
        q.push(1);
        int sommetCur;
        while (!q.empty()){
            sommetCur=q.front();
            q.pop();
            bool dejaVu=false;
            int pariteMult=0;
            for (auto voisin : adj[sommetCur]){
                if (adj[voisin].size()>1){
                    pariteMult++;
                }
                if (vu[voisin] && 3-vu[voisin]!=vu[sommetCur]){
                    ok=false;
                }
                if (vu[voisin] && adj[voisin].size()>1) dejaVu=true;
                if (!vu[voisin]){
                    vu[voisin]=3-vu[sommetCur];
                    q.push(voisin);
                }
            }
            if (pariteMult>2) ok=false;
            else if (pariteMult==1 && adj[sommetCur].size()==1){}
            else if (pariteMult) tot*=2LL*fact[adj[sommetCur].size()-pariteMult];
            else tot*=fact[adj[sommetCur].size()];
            if (dejaVu && adj[sommetCur].size()>1) tot/=2LL;
            tot%=mod;
      //      cout << sommetCur << " " << pariteMult<<" "<< tot << endl;
        }
        for (int i=1;i<=n;i++){
            if (!vu[i]) ok=false;
        }
        if (ok) cout<<tot<<endl;
        else cout<<0<<endl;
    }
}