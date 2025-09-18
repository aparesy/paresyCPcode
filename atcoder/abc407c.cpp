#include <bits/stdc++.h>

using namespace std;

int main(){
    string s;
    cin >> s;
    int tot=0;
    for (int i=0;i<s.length()-1;i++){
        tot+=1;
        int a=(int)(s[i]-'0');
        int b=(int)(s[i+1]-'0');
  //      cout << ((a-b+10)%10) << endl;
        tot+=(a-b+10)%10;
    }
    cout << tot+(int)(s[s.length()-1]-'0')+1;
}