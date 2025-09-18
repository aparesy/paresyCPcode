#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define vi vector<int>
#define vl vector <ll>
#define loop(n) for(int i=0;i<n;i++)

int main(){
    int t;
    cin >> t;
    while (t--){
        int n;
        cin>>n;
        vl v(n);
        for (auto& x : v)cin>>x;
        unordered_map<int,int> prec; // Indice de la dernière apparition de i;
        vector<int> suiv(n,-1); //Indice de l'apparition suivante
        for (int i=0;i<n;i++){
            int elem=v[i];
            if (prec.find(elem)==prec.end()){
                prec[elem]=i;
            }
            else{
                suiv[prec[elem]]=i;
                prec[elem]=i;
            }
        }
        int lbound=0;
        int rbound=0;
        int count=0;
        for (int i=0;i<n;i++){
            int curSuiv=((suiv[i]==-1)?n:suiv[i]);
            rbound=max(curSuiv, rbound);
            if (i==lbound){
                count++;
                lbound=rbound;
            }
        }
        cout<<count<<endl;
    }
}