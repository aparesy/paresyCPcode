#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int x;
        cin>>x;
        string s;
        cin>>s;
        x--;
        int countLeft=0;
        while(countLeft<=x && s[x-countLeft]=='.' ) countLeft++;
        int countRight=0;
        while(x+countRight<n && s[x+countRight]=='.') countRight++;
        if (x==0 || x==n-1){
            cout<<1<<endl;
        }
        else{
            countLeft=x-countLeft+1;
            countRight=n-(x+countRight);

//           cout<< countLeft << " "<<countRight<<endl;
//            cout<<max(countLeft, countRight)+1<<endl;
            if (countLeft<countRight){
                cout<<(min(x+1, countRight+1))<<endl;
            }
            else{
                cout<<(min(n-x, countLeft+1))<<endl;
            }
        }
    }
}