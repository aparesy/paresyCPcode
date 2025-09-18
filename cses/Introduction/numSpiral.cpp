#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        ll y,x;
        cin>>y>>x;
        bool hmm = (x>=y);
        ll maxi=hmm?x:y;
        if ((maxi+hmm)%2){
            cout << maxi*maxi-maxi-abs(y-x)+1LL;
        }
        else cout<<maxi*maxi+abs(y-x)+1LL-maxi;
        cout<<endl;
    }
}