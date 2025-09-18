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
        cin>>n;
        vl v(n);
        for (auto& x : v)cin>>x;
        sort(v.begin(),v.end());
        if (v[0]==v[n-1]){
            cout<<-1<<endl;
        }
        else{
            int maxi=0;
            for (int i=0;i<n;i++){
                if (v[i]!=v[n-1]){
                    maxi=i;
                }
            }
            cout<<maxi+1<<" "<<n-maxi-1<<endl;
            for (int i=0;i<=maxi;i++){
                cout<<v[i]<<" ";
            }
            cout<<endl;
            for (int i=maxi+1;i<n;i++){
                cout<<v[i]<<" ";
            }
            cout<<endl;
        }
    }
}