#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define vi vector<int>
#define vl vector <ll>

int main(){
    int t;
    cin >> t;
    while (t--){
        int tot=0;
        vector<string> v(10);
        for (auto& x : v) cin>>x;
        for(int i=0;i<10;i++){
            for (int j=0;j<10;j++){
                if (v[i][j]=='X'){
                    tot+=min(min(i+1,10-i), min(j+1,10-j));
                }
            }

        }
        cout<<tot<<endl;
    }
}