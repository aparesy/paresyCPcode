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
        string s;
        cin>>n;
        cin>>s;
        int tot=1;
        unordered_map<char,bool> tab;
        tab[s[0]]=true;
        int distinct=0;
        for (int i=1;i<n;i++){
            if (tab.find(s[i])==tab.end()){
                distinct++;
                tab[s[i]]=true;
            }
            tot+=(1+distinct);
        }
        cout<<tot<<endl;
    }
}
