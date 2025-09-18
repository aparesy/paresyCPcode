#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define vi vector<int>
#define vl vector <ll>

int main(){
    int t;
    cin >> t;
    while (t--){
        int a,b,c;
        cin>>a>>b>>c;
        if (c<max(a,b)){
            cout<<"No\n";
        }
        else if (c>=a+b+2){
            cout<<"No\n";
        }
        else if (c<=a+b){
            cout<<"Yes\n";
            ll x=pow(10,max(a,b)-1);
            ll y=pow(10,a+b-max(a,b)-1);
            while (log10(x*y)+1LL<c){
                y*=2LL;
            }
            cout<<x<<" "<<y<<endl;
        }
    }
}