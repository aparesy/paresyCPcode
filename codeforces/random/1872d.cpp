#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define vi vector<int>
#define vl vector <ll>

ll sumto(ll n){
    return n*(n+1)/2;
}

ll sumfromto(ll m, ll n){
    return sumto(n)-sumto(m);
}

int main(){
    int t;
    cin >> t;
    while (t--){
        ll n,x,y;
        cin>>n>>x>>y;
        int nbX = n/x-(n/lcm(x,y));
        int nbY = n/y-(n/lcm(x,y));
        cout<<sumfromto(n-nbX,n)-sumto(nbY)<<endl;
    }
}
