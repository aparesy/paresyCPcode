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
        vector<int> v(n*(n-1)/2);
        for (auto& x : v)cin>>x;
        sort(v.begin(), v.end());
        int j=0;
        for (int i=n-1;i>0;i--){
            cout<<v[j]<<" ";
            j+=i;
        }
        j-=1;
        cout<<v[j]<<endl;
    }
}