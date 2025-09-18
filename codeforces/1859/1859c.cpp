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
        ll tot=0;
        if (n==2){
            cout<<2<<endl;
        }
        else if (n==3){
            cout<<7<<endl;
        }
        else{
            ll tot=0;
            ll maxTot=0;
            for (int i=n;i>=n/2;i--){
                tot=0;
                for (int j=1;i-j>n-i;j++){
                    tot+=j*j;
                }
                for (int j=2*i-n;j<=n;j++){
                    if (j!=i){
                        tot+=j*(2*i-j);
                    }
                }
                if (tot>maxTot){
                    maxTot=tot;
                }
            }
            cout<<maxTot<<endl;
        }
    }
}
