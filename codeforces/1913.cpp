#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define vi vector<int>
#define vl vector <ll>

int main(){
    int t;
    cin >> t;
    while (t--){
        string s;
        cin>>s;
        bool majo=false;
        char cur=s[0];
        int n=s.length();
        int nb_cur=1;
        for (int i=1;i<n;i++){
            if (s[i]==cur){
                nb_cur++;
            }
            else nb_cur--;
            if (nb_cur==0){
                cur=s[i];
                nb_cur=1;
            }
        }
        nb_cur=0;
        vi nb_maj(n);
        int maxi=n;
        for (int i=0;i<n;i++){
            if (s[i]==cur) nb_cur++;
            nb_maj[i]=nb_cur;
        }
        if (nb_cur>n/2) majo = true;
        bool fini=false;
        if (majo){
            for (int i=0;i<n&&!fini;i++){
                if (nb_maj[n-i-1]<=n-nb_cur){
    //                cout<<"test : "<<t<<" "<<i<<endl;
                    maxi=i;
                    fini=true;
                }
            }
            cout<<maxi<<endl;
        }
        else{
   //         cout<<"test : "<<t<<endl;
            cout<<0<<endl;
        }
    }
}
