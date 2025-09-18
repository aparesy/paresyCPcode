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

vi parent;

void make_set(int v) {
    parent[v] = v;
}

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}


void union_sets2(int a, int b) {
    // a est ajouté au-dessus de b
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        parent[b] = a;
    }
}


// void union_sets(int a, int b,int edge) {
//     if (parent[a]==a){
//         parent[a]=edge;
//     }
//     if (parent[b]==b){
//         parent[b]=edge;
//     }
//     parent[repr[a]]=edge;
//     parent[repr[b]]=edge;
//     repr[repr[a]]=edge;
//     repr[repr[b]]=edge;
//     repr[a]=edge;
//     repr[b]=edge;

// }

int n,m,k;

void dfsTarjan(int node, unordered_map<int,vi>& h, vvi& tarjanTree, vi& answer, vector<vii>& requetes, vii& idToRequete, vb& vu){
    //En entrée du noeud : on traite les requetes
    vu[node]=true;
    for (auto id : h[node]){
        answer[id]=find_set(idToRequete[id].first==node?idToRequete[id].second:idToRequete[id].first);
    }
    //Traitement des enfants avec fusion à la fin
    for (auto t : tarjanTree[node]){
        dfsTarjan(t,h,tarjanTree,answer,requetes,idToRequete,vu);
        union_sets2(node,t);
    }
    // En sortie du noeud : on ajoute les requetes
    if (node<n) for (auto [t,id] : requetes[node]){
        h[t].push_back(id);
    }
}


void solve(){
    cin>>n>>m>>k; n++;
    priority_queue<pair<int,int>, vector<pii>, greater<pii>> q;

    // Reset de l'union-find

    parent.resize(n+m);
    rep(i,0,n+m){
        make_set(i);
    }

    //Input des arêtes (de 1 à m)

    vector<pair<int,pii>> aretes(m);
    vector<vector<int>> tarjanTree(n+m);
    rep(i,0,m){
        int a,b,c;
        cin>>a>>b>>c;
        aretes[i]={c,{a,b}};
        q.push({c,i});
    }

    // Création de TarjanTree

    int tot_taken=0;
    stack<int> lastTaken;
    while(tot_taken<n-2 && !q.empty()){
        auto [poids, id]=q.top();
        q.pop();
        auto [i,j]=aretes[id].second;
        if (find_set(i)!=find_set(j)){
            tot_taken++;
            tarjanTree[id+n].push_back(find_set(i));// tarjanTree[i].push_back(id+n);
            tarjanTree[id+n].push_back(find_set(j)); // tarjanTree[j].push_back(id+n);   
            union_sets2(id+n,i);
            union_sets2(id+n,j);
            lastTaken.push(id+n);
        }
    }

    // Insertion des requêtes sous forme de graphe (voisin,id)


    vector<vector<pii>> requetes(n);
    vector<pii> idToRequete(k);
    rep(i,0,k){
        int a,b;
        cin>>a>>b;
        requetes[a].push_back({b,i});
        requetes[b].push_back({a,i});
        idToRequete[i] = {a,b};
    }
    vector<int> answer(k);

    // Reset de l'UF et exécution de Tarjan dans l'arbre
    // h sert à savoir quelles requêtes sont à traiter pour un node donné

    unordered_map<int,vi> h;
    rep(i,0,n+m) make_set(i);
    vb vu(n+m);
    while (!lastTaken.empty()){
        if (!vu[lastTaken.top()])
        dfsTarjan(lastTaken.top(),h,tarjanTree, answer, requetes, idToRequete,vu);
        lastTaken.pop();
    }

    rep(i,0,k){
        cout<<aretes[answer[i]-n].first<<"\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}