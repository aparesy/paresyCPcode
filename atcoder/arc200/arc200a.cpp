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
        ll n;
        cin>>n;
        vl a(n);
        for (auto& x : a)cin>>x;
        vl b(n);
        for (auto& x  : b)cin>>x;
        // On choisit toujours 0
        ll vAutre=-1;
        for (int i=1;vAutre==(-1)&&i<n;i++){
            if (a[0]*b[i] != b[0]*a[i]){
                vAutre=i;
            }
        }
        if (vAutre==-1){
            cout<<"No\n";
        }
        else if (a[0]*b[vAutre]>b[0]*a[vAutre]){
            ll c1=a[vAutre]/a[0]+1;
            ll c2=(b[0]*c1)/b[vAutre]+1;
            c2=-c2;
            cout<<"Yes\n";
            cout<<c1<<" ";
            for (int i=1;i<n;i++){
                if (i==vAutre){
                    cout<<c2<<" ";
                }
                else cout<<0<<" ";
            }
            cout<<endl;
        }
        else{
            ll c2=a[0]/a[vAutre]+1;
            ll c1=(b[vAutre]*c2)/b[0]+1;
            c1=-c1;
            cout<<"Yes\n";
            cout<<c1<<" ";
            for (int i=1;i<n;i++){
                if (i==vAutre){
                    cout<<c2<<" ";
                }
                else cout<<0<<" ";
            }
            cout<<endl;
        }
    }
}