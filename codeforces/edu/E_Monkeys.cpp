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

vi tps;

// Go through the orders in reverse order
// Plus ou moins le mm probleme, forward pass : on retire les aretes en question ; backward pass : si on fusionne avec 1 on marque
// On stocke les représentants dans la foret initiale et lors d'une union qui n'implique pas 1 on actualise
struct uf{
    vi p;
    vi r;
    void init(int n){
        p.resize(n);
        rep(i,0,n) p[i]=i;
        r.resize(n);
    }

    int get(int a){
        return p[a]=(p[a]==a?a:get(p[a]));
    }

    void uni(int a, int b, bool ok){
        a=get(a);
        b=get(b);
        if (r[a]==r[b])r[a]++;
        if (r[a]>r[b]){
            p[b]=a;
            if (ok) tps[a]=max(tps[b],tps[a]);
        }
        else{
            p[a]=b;
            if (ok) tps[b]=max(tps[b],tps[a]);
        }
    }
};

void solve(){
    int n,q;
    // Initialisation du graphe
    cin>>n>>q;n++;
    uf tmp;
    uf tmp2;
    tmp.init(n);
    tmp2.init(n);
    vector<pii> adj(n);
    rep(i,1,n){
        int a,b;
        cin>>a>>b;
        adj[i].first=a;   
        adj[i].second=b;
    }
    vii adj2 = adj; // On copie le graphe G1 pour avoir les anciens liens


    // Récupération des requêtes pour la bw pass et on délie les mains en question
    vector<pair<int,int>> reqs;
    rep(i,0,q){
        int a,b;cin>>a>>b;
        reqs.push_back({a,b});
        if (b==1){
            adj[a].first=-1;
        }
        else adj[a].second=-1;
    }

    // 
    rep(i,1,n){
        if (adj[i].first != -1) tmp.uni(adj[i].first,i,false);
        if (adj[i].second != -1) tmp.uni(adj[i].second,i,false);
        if (adj[i].first != -1) tmp2.uni(adj[i].first,i,false);
        if (adj[i].second != -1) tmp2.uni(adj[i].second,i,false);
    }

    tps.resize(n); 

    for (int i=q-1;i>=0;i--){
        auto [a,b]=reqs[i];
        if (b==1){
            // On accrche la premiere main
            if (tmp.get(a)!=tmp.get(1)){
                if (tmp.get(adj2[a].first) != tmp.get(1)){
                    tmp2.uni(adj2[a].first,a,true);
                }
                else{
                    tps[tmp2.get(a)]=i;
                }
            }
            else{
                if(tmp.get(adj2[a].first)!=tmp.get(1)){
                    tps[tmp2.get(adj2[a].first)]=i;
                }
            }
            tmp.uni(adj2[a].first,a,false);
        }
        else{
            // On accrche la premiere main
            if (tmp.get(a)!=tmp.get(1)){
                if (tmp.get(adj2[a].second) != tmp.get(1)){
                    tmp2.uni(adj2[a].second,a,true);
                }
                else{
                    tps[tmp2.get(a)]=i;
                }
            }
            else{
                if(tmp.get(adj2[a].second)!=tmp.get(1)){
                    tps[tmp2.get(adj2[a].second)]=i;
                }
            }
            tmp.uni(adj2[a].second,a,false);
        }
    }
    rep(i,1,n){
        int repr = tmp2.get(i);
        if (repr == tmp2.get(1)){
            cout<<-1<<"\n";
        }
        else{
            cout<<tps[repr]<<"\n";
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}