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
        cout<<1<<" ";
        for (int i=n;i>=3;i--){
            cout << i << " ";
        }
        cout << 2 <<endl;
    }
}