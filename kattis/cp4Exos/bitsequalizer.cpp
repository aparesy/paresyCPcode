#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for (int i=a;i<b;i++)

int main(){
    int c;
    cin>>c;
    rep(cas,1,c+1){
        cout<<"Case "<<cas<<": ";
        string s,t;
        cin>>s>>t;
        int n=s.length();
        pair<int,int> countOnes;
        countOnes.first=0;
        countOnes.second=0;
        rep(i,0,n){
            if (s[i]=='1') countOnes.first++;
            if (t[i]=='1') countOnes.second++;
        }
        if (countOnes.first>countOnes.second){
            cout<<"-1\n";
            continue;
        }
        int tot=0;
        pair<int,int> paires={0,0};
        rep(i,0,n){
            if(s[i]=='0' && t[i]=='1') paires.first++;
            if (s[i]=='1' && t[i]=='0') paires.second++;
        }
        rep(i,0,n){
            if (s[i]=='?') tot++;
        }
        cout<<max(paires.first, paires.second) + tot    <<"\n";
    }
}