#include <vector>
#include <iostream>

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
        vector<int> v(n);
        for (auto& x : v)cin>>x;
        if (n==1){
            cout<<1<<endl;
        }
        else{
            int mini=v[0];
            int maxi=v[0];
            bool pente=v[1]>=v[0];
            for (int i=0;i<n;i++){
                if (mini>v[i]){
                    mini=v[i];
                }
                else if (maxi<v[i]){
                    maxi=v[i];
                }

            }
        }
        
    }
}