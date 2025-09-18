#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll s;
        cin>>s;
        vl tab(n);
        for (auto& x : tab) cin>>x;
        ll sum=0;
        vector<int> compte(3,0);
        for (int i=0;i<n;i++){
            compte[tab[i]]++;
            sum+=tab[i];
        }
        if (sum>s){
            for (int i=0;i<n;i++){
                cout << tab[i] << " ";
            }
        }
        else if (sum+1==s){
            for (int i=0;i<compte[0];i++)cout<<0<<" ";
            for (int i=0;i<compte[2];i++)cout<<2<<" ";
            for (int i=0;i<compte[1];i++)cout<<1<<" ";
            
        }
        else{
            cout<<-1;
        }
        cout<<endl;
    }
}