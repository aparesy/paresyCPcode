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
        int grid[n][n];
        for (int i=0;i<n;i++){
            for (int j=0;j<n;j++){
                cin >> grid[i][j];
                grid[i][j]--;
            }
        }
        vector<bool> vu(2*n);
        for (int i=0;i<n;i++){
            vu[grid[0][i]]=true;
        }
        for (int j=0;j<n;j++){
            vu[grid[j][n-1]]=true;
        }
        for (int i=0;i<2*n;i++){
            if (!vu[i]) cout<<i+1<<" ";
        }
                for (int i=0;i<n;i++){
            cout<<grid[0][i]+1<<" ";
        }
        for (int j=1;j<n;j++){
            cout<<grid[j][n-1]+1<<" ";
        }
        cout<<endl;
    }
}