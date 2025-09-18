#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        vector<ll> v(n);
        vector<ll> p(n);
        for (int i=0;i<n;i++){
            cin >> v[i] >> p[i];
        }
        unordered_map<ll,vector<int>> lienV;
        for (int i=0;i<n;i++){
            lienV[v[i]].push_back(i);
        }
        unordered_map<ll,vector<int>> lienP;
        for (int i=0;i<n;i++){
            lienP[p[i]].push_back(i);
        }
        vector<bool> vu(n,0);
        vector<int> chemin;
        int debut = (lienV[v[0]].size()==1);
        int parite=debut;
        int cur=0;
        chemin.push_back(cur);
        vu[cur]=true;
        vector<int> noeud = (parite)?lienP[p[cur]]:lienV[v[cur]];
        bool fini=false;
        while (noeud.size()!=1&&!fini){
            fini=true;
            for (auto e : noeud){
                if (fini && e!=cur && !vu[e]){
                    fini=false;
                    cur=e;
                    vu[e]=true;
                    parite = 1-parite;
                    noeud = (parite)?lienP[p[cur]]:lienV[v[cur]];
                    chemin.push_back(cur);
                }
            }
        }
        cur=0;
        vector<int> chemin2;
        fini=false;
        parite=1-debut;
        noeud = (parite)?lienP[p[cur]]:lienV[v[cur]];
        while (noeud.size()!=1&&!fini){
            fini=true;
            for (auto e : noeud){
                if (fini && e!=cur && !vu[e]){
                    fini=false;
                    cur=e;
                    vu[e]=true;
                    parite = 1-parite;
                    noeud = (parite)?lienP[p[cur]]:lienV[v[cur]];
                    chemin2.push_back(cur);
                }
            }
        }
        bool ok=true;
        for (int i=0;i<n;i++){
            if (!vu[i]) ok = false;
        }
        if (ok){
            cout << "YES" << endl;
            for (int i=chemin2.size()-1;i>=0;i--) cout << chemin2[i]+1 << " ";
            for (auto x : chemin) cout << x+1 << " ";
            cout << endl;
        }
        else cout << "NO" << endl;
    }
}