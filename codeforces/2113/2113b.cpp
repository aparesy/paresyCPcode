#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define vi vector<int>
#define vl vector <ll>

int main(){
    int t;
    cin >> t;
    while (t--){
        ll w,h,a,b;
        cin>>w>>h>>a>>b;
        ll x1,y1;
        cin>>x1>>y1;
        ll x2,y2;
        cin>>x2>>y2;
        bool bien1 = ((x1-x2)%a==0);
        bool bien2 = ((y1-y2)%b==0);
        bool overlapX = (abs(y1-y2)<b);
        bool overlapY = (abs(x1-x2)<a);
        if (overlapX && overlapY){
            cout<<"Pas possible";
        }
        else if (overlapX){
            if(bien1)cout<<"Yes"; else cout<<"No";
        }
        else if (overlapY){
            if(bien2)cout<<"Yes"; else cout<<"No";
        }
        else if(bien2||bien1)cout<<"Yes"; else cout<<"No";
        cout<<"\n";
    }
}
