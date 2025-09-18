#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>

bool score_possible(string s, ll n, ll k, ll score){

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        ll n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        vector<int> cumZero(n,0);
        cumZero[0]=(s[0]=='0');
        for (int i=1;i<n;i++){
            cumZero[i]=cumZero[i-1]+(s[i]=='0');
        }
    }
}