#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define vi vector<int>
#define vl vector <ll>


bool is_substr(string s, string t, int n, int m){
    for (int i=0; i<m-n+1;i++){
  //      cout << t << " " << i << " " << n;
        if (t.substr(i, n)==s) return true;
    }
    return false;
}

int main(){
    int t;
    cin >> t;
    while (t--){
        int n,m;
        cin>>n>>m;
        string s;
        string t;
        cin>>s>>t;
        bool fini=false;
        int k=0;
        for (int i=0;!fini&&( i<=2 || t.length()*4>=s.length()/2);i++){
            if(is_substr(t, s, m, n)){
                fini=true;
                k=i;
            }
            s=s+s;
            n*=2;
 //           cout<<s.length()<<endl;
        }
        if (fini) cout<<k<<endl;
        else cout<<-1<<endl;
    }
}
