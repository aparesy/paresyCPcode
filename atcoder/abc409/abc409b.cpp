#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define vl vector <ll>
#define loop(n) for(int i=0;i<n;i++)

int main(){
    int n;
    cin>>n;
    vl v(n);
    for (auto& x : v)cin>>x;
    int tab[101];
    for (int i=0;i<101;i++){
        tab[i]=0;
    }
    for (int i=0;i<101;i++){
        for (auto k : v){
            if (k>=i){
                tab[i]++;
            }
        }
    }
    int maxi=0;
    for (int i=0;i<101;i++){
        if (tab[i]>=i){
            maxi=i;
        }
    }
    cout<<maxi<<endl;
}