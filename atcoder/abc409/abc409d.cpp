#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define vi vector<int>
#define vl vector <ll>
#define loop(n) for(int i=0;i<n;i++)

int main(){
    int t;
    cin >> t;
    while (t--){
        int n;
        string s;
        cin>>n>>s;
        int l=0;
        bool fini=false;
        string sorted=s;
        sort(sorted.begin(), sorted.end());
        for (int i=0;!fini&&i<n-1;i++){
            if (s[i]>s[i+1]){
                fini=true;
                l=i;
            }
        }
        if (!fini) cout<<s<<endl;
        else{
            fini=false;
            int r=n;
            for (int i=l+1;i<n&&!fini;i++){
                if (s[i]>s[l]){
                    fini=true;
                    r=i;
                }
            }
 //           cout<<l<<" "<<r<<endl;
            if (r==n) cout<<s.substr(0,l)+s.substr(l+1,r-l)+s[l]<<endl;
            else cout<<s.substr(0,l)+s.substr(l+1,r-l-1)+s[l]+s.substr(r,n-r+1)<<endl;
        }
    }
}