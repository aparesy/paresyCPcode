#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define vi vector<int>
#define vl vector <ll>

int main(){
    int t;
    cin >> t;
    while (t--){
        int n,m,l,r;
        cin>>n>>m>>l>>r;
        int a=0;
        int b=0;
        for (int i=0;i<m;i++){
            if (a==l){
                b++;
            }
            else a--;
        }
        cout << a << " "<<b<< endl;
    }
}