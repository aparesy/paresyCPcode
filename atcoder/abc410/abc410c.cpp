#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define vi vector<int>
#define vl vector <ll>

int main(){
    ll n;
    cin>>n;
    ll q;
    cin>>q;
    ll decalage=0;
    vl v(n);
    for (int i=0;i<n;i++){
        v[i]=i+1;
    }
    int req;
    ll p;
    ll x;
    ll k;
    for(int i=0;i<q;i++){
        cin>>req;
 //       cout<<req<<"ok"<<endl;
        if (req==1){
            cin>>p>>x;
            v[(p-1+decalage)%n] = x; 
        }
        else if (req==2){
            cin>>p;
            cout<< v[(p-1+decalage)%n]<<endl;
        }
        else{
            cin>>k;
            decalage+=k;
            decalage=decalage%n;
        }
    }
}