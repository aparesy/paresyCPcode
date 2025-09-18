#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define vi vector<int>
#define vl vector <ll>

int main(){
    int n;
    cin>>n;
    vl v(n);
    for (auto& x : v)cin>>x;
    int k;
    cin>>k;
    int tot=0;
    for (auto x : v){
        if (k<=x) tot++;
    }
    cout<<tot<<endl;
}