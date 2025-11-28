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

// Question : comment gérer l'xp pour pas ajouter après une union MAIS ajouter dans l'arbre APRES les add
// Réponse : Quand on union, redistribuer l'xp aux enfants
//Un peu cher ?
// Pas de path compression mais size sur l'arbre pour une complexité raisonnable

struct uf{
    vi p,r;
    vl xp;
    void init(int n){
        p.resize(n);
        rep(i,0,n){
            p[i]=i;
        }
        r.resize(n);
        rep(i,0,n) r[i]=1;
        xp.resize(n);
    }

    ll get(int a){ // Renvoie l'xp
        if (p[a]==a) return xp[a];
        else return xp[a]+get(p[a]);
    }

    void add(int a, ll x){
        while (a!=p[a]) a=p[a];
        xp[a]+=x;
    }

    void uni(int a, int b){
        // Avant de joindre = redonner aux enfants (équivalent à compenser pour b)
        while(a!=p[a]) a=p[a];
        while(b!=p[b]) b=p[b];
        if (a==b) return;
        if (r[a]>r[b]){
            xp[b]-=xp[a];
            p[b]=a;
            r[a]+=r[b];
        }
        else{
            p[a]=b;
            r[b]+=r[a];
            xp[a]-=xp[b];
        }
    }
};

void solve(){
    int n,q;
    cin>>n>>q;
    uf tmp;
    tmp.init(n+1);
    rep(i,0,q){
        string s;
        cin>>s;
        ll a,b;
        if (s[0]=='j'){
            cin>>a>>b; 
            tmp.uni(a,b);
        }
        else if (s[0]=='a'){
            cin>>a>>b; 
            tmp.add(a,b);
        }
        else{
            cin>>a;
            ll res=tmp.get(a);
            cout<<res<<endl;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}