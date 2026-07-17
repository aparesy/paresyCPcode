#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define vi vector<int>
#define vl vector <ll>

int main(){
    int t;
    cin >> t;
    while (t--){
        ll a,b;
        ll c,d;
        ll e,f;
        cin>>a>>b;
        cin>>c>>d;
        cin>>e>>f;

        if ((abs(c-e)==2*a)){
            if (abs(d-f)==0){
                cout<<2<<endl;
            }
            else if (abs(d-f)==2*b){
                if (a==b){
                    cout<<1<<endl;
                }
                else cout<<2<<endl;
            }
            else cout<<0<<endl;
        }
        else if ((abs(c-e)==2*b)){
            if (abs(d-f)==0){
                cout<<2<<endl;
            }
            else if (abs(d-f)==2*a){
                if (a==b){
                    cout<<1<<endl;
                }
                else cout<<2<<endl;
            }
            else cout<<0<<endl;
        }
        else if ((abs(c-e)==a+b)){
            if (abs(d-f)==a+b){
                cout<<2<<endl;
            }
            else if (abs(d-f)==abs(a-b)){
                cout<<2<<endl;
            }
            else cout<<0<<endl;
        }
        else if ((abs(c-e)==abs(a-b))){
            if (a==b){
                if (abs(d-f)==2*a){
                    cout<<2<<endl;
                }
                else cout<<0<<endl;
            }
            else if (abs(d-f)==a+b){
                cout<<2<<endl;
            }
            else if (abs(d-f)==abs(a-b)){
                cout<<2<<endl;
            }
            else cout<<0<<endl;
        }
        else cout<<0<<endl; 
    }
}
