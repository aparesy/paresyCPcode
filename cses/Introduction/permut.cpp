#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    if (n==1) cout << 1;
    else if (n<=3){
        cout<<"NO SOLUTION";
    }
    else if (n==4) cout <<"2 4 1 3";
    else{
        for (int i=0;i<n;i+=2){
            cout << i+1<<" ";
        }for (int i=1;i<n;i+=2){
            cout << i+1<<" ";
        }
    }
}