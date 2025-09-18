#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    string s;
    cin>>s;
    vector<int> color(n,0);
    // char maxi='a';
    // for (int i=0;i<n;i++){
    //     if (s[i]<maxi){
    //         color[i]=1;
    //     } else {
    //         color[i]=0;
    //     }
    //     if (s[i]>maxi){
    //         maxi=s[i];
    //     } 
    // }
    // char maxZero='a';
    // char maxOne='a';
    // bool ok=true;
    // for (int i=0;i<n;i++){
    //     if (color[i]==0&&s[i]>maxZero){
    //         maxZero=s[i];
    //     } else if (color[i]==1&&s[i]>maxOne){
    //         maxOne=s[i];
    //     } else if (color[i]==0&&s[i]<maxZero){
    //         ok=false;
    //     } else if (color[i]==1&&s[i]<maxOne){
    //         ok=false;
    //     }
    // }
    // if (ok){
    //     cout<<"YES\n";
    //     for (int i=0;i<n;i++){
    //         cout<<color[i];
    //     }
    //     cout<<"\n";
    // } else {
    //     cout<<"NO\n";
    // }

    // C'est une histoire de tableaux trié avec en mémoire le cur Max de la couleur et la couleur
    // On doit pouvoir trouver le curMax le plus grand qui soit plus petit que cur en log n
    set<pair<char, int>> curMax;
    int colorMax=0;
    for (int i = 0; i < n; i++) {
        auto it = curMax.upper_bound({s[i], INT_MAX});
        if (it==curMax.begin()) {
            // Si on est au début, on ne peut pas prendre de curMax
            color[i] = ++colorMax; // On crée une nouvelle couleur
            curMax.insert({s[i], color[i]}); // On ajoute le cur avec sa couleur
            continue;
        }
        else{
            it--;
            color[i] = it->second; // On prend la couleur du curMax
            curMax.erase(it);
            curMax.insert({s[i], color[i]});
        }
    }
    cout<<colorMax << "\n"; // On affiche le nombre de couleurs
    for (int i=0;i<n;i++){
        cout<<color[i]<<" ";
    }
        
}