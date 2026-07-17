#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define vi vector<int>
#define vl vector <ll>

int main(){
    int t;
    cin >> t;
    while (t--){
        ll n,k;
        cin>>n>>k;
        if (k%2==0){
            for (int i=0;i<n-2;i++){
                cout << n-1 << " ";
            }
            cout << n << " ";
            cout << n-1 << endl;
        }
        else{
            for (int i=0;i<n-1;i++){
                cout << n << " ";
            }
            cout << n-1 << endl;
        }
    }
}