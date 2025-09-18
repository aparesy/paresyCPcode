#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    string s;
    cin>>s;
    int n=s.length();
    int tot=0;
    vector<int> nb(n);
    for (int i=0;i<n;i++){
        if (i){
            nb[i]=nb[i-1];
        }
        if (s[i]=='('){
            tot++;
            nb[i]++;
        }
    }
    ll res=0LL;
    for(int i=0;i<n;i++){
        if (s[i]=='('){
            
        }
    }
}