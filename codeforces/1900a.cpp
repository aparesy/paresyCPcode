#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define vi vector<int>
#define vl vector <ll>

int main(){
    int t;
    cin >> t;
    while (t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        int i=0;
        int tot=0;
        bool ok=false;
        for (int i=0;i<n;i++){
            if (i<n-2 && s[i]=='.'&&s[i+1]==s[i]&&s[i+2]==s[i]){
                ok=true;
            }
            else if (s[i]=='.'){
                tot++;
            }
        }
        if(ok)cout<<2; else cout<<tot; cout<<endl;
    }
}