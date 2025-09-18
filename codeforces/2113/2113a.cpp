#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define vi vector<int>
#define vl vector <ll>

int main(){
    int t;
    cin >> t;
    while (t--){
        ll k,a,b,x,y;
        cin>>k>>a>>b>>x>>y;
        ll tot=0LL;
        if (x<y){
            tot+=max(0LL,(k-a+x)/x);
            if (b>=a){
                cout<<tot;
            }
            else{
                cout<<tot + max(0LL,(k-tot*x-b+y)/y);
            }
        }
        else{
            tot+=max(0LL,(k-b+y)/y);
            if (a>=b){
                cout<<tot;  
            }
            else{
                cout<<tot+max(0LL,(k-tot*y-a+x)/x);
            }
        }
        cout<<endl;
    }
}
