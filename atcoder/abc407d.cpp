#include <bits/stdc++.h>

using namespace std;

#define ll unsigned long long

int main(){
    int h,w;
    cin >> h >> w;
    vector<vector<ll>> grid(h, vector<ll>(w,0));
    for (int i=0;i<h;i++){
        for (int j=0;j<w;j++){
            cin >> grid[i][j];
        }
    }

    //Branch and bound

    vector<vector<int>> state(h, vector<int>(w,0));
    int maxi=0;
    for (int b=62;b>=0;b++){
            
    }


 /**    for (int i=0;i<h;i++){
        for (int j=0;j<w;j++){
            cout <<  grid[i][j] << " ";
        }
    } **/
}