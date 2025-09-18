#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while (t--){
        string s;
        cin >> s;
        bool trouve=false;
        int count=1;
        for (int i=1;i<s.length()-1;i++){
            if (s[i]=='(') count++;
            else count--;
            if (count == 0) trouve=true;
        }
        if (trouve) cout << "YES"; else cout << "NO";
        cout << endl;   
    }
}