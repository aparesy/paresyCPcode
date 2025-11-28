// Useful functions : nth_element, rotate, unique, merge, count, generate

#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define pdd pair<double,double>
#define vi vector<int>
#define vii vector<pii>
#define vvi vector<vector<int>>
using ll=long long;
#define vl vector<ll>
#define vvl vector<vector<ll>>
#define vb vector<bool>
#define F first 
#define S second
#define rep(i,a,b) for(int i=a;i<b;i++)
#define input(tab) for (auto& x : tab)cin>>x
#define all(x) x.begin(),x.end()

ll get(){
   ll x;
   cin>>x;
   return x;
}

void solve(){
    string a,b;
    getline(cin,a);
    getline(cin,b);
    int n=a.length(); int m=b.length();
    int i=0;
    int j=0;
    set<char> vus;
    while(i<n){
        char c=a[i];
        int totA=0;
        while (i<n && a[i]==c){
            totA++;
            i++;
        }
        int totB=0;
        while(j<m && b[j]==c){
            totB++;
            j++;
        }
//        cout<<c<<totA<<totB;
        if (totB>totA && !vus.count(c)){
            vus.insert(c);
            cout<<c;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}