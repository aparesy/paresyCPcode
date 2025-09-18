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
        vl a(n);
        vl b(n);
        for (auto& x : a)cin>>x;
        for (auto& x : b)cin>>x;
        for (int i=0;i<n;i++){
            if (i%2){
                ll tmp = a[i];
                a[i]=b[i];
                b[i]=tmp;
            }
        }
        int maxi=-1;
        unordered_map<ll,int> h1;
        unordered_map<ll,int> h2;
        for (int i=0;i<n;i++){
            // h1(elem) : indice de la dernière apparition de elem
            h1[a[i]]=i;
            h2[b[i]]=i;
            if (h1.find(b[i]) != h1.end() && h1[b[i]]>maxi){
                maxi=h1[b[i]];
            }
            if (h2.find(a[i]) != h2.end() && h2[a[i]]>maxi){
                maxi=h2[a[i]];
            }
        }
        // maxi := score sans découpage
        // On trouve les plus gros sur la même phase. Score : min_ind+1
        for (int i=0;i<n;i++){
            if (i>maxi && (h1[a[i]] != i)  && (h1[a[i]]-i!=1)){
                maxi=i;
            }
            if (i>maxi && (h2[b[i]] != i)  && (h2[b[i]]-i!=1)){
                maxi=i;
            }
        }
        cout<<maxi+1<<endl;
    }
}