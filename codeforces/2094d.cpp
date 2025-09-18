#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;
    while (t--){
        string p; cin>>p;
        string s; cin >> s;
        int n=p.length();
        int m=s.length();
        int i=0; int j=0;
        bool fini=false;
        while (!fini && i<n && j<m){
            if (p[i] != s[j]){
                fini=true;
            }
            else{
                char c=p[i];
                int count1=0;
                int count2=0;
                while(i<n && p[i]==c){
                    count1++;
                    i++;
                }
                while (j<m && s[j]==c){
                    count2++;
                    j++;
                }
                if (count2<count1){
                    fini=true;
                }
                if (count2>2*count1){
                    fini=true;
                }
            }
        }
        if (fini || i!=n || j!=m){
            cout<<"NO\n";
        }
        else cout<<"YES\n";
    }

}