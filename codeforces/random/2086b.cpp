#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define vi vector<int>
#define vl vector <ll>

int main(){
    int t;
    cin >> t;
    while (t--){
        int n,k;
        ll x;
        cin >>n>>k>>x;
        vl v(n);
        for (auto& y : v) cin >> y;
        ll s = reduce(v.begin(), v.end());
        if (s==0) cout<< 0<<endl;
        else if (x>s*k) cout<<0<<endl;
        else if (x==s*k) cout <<1<<endl;
        else{
           int i=0;
           ll reste = -x%s;
           ll tot = n*(max(k-(x/s), (ll)0))+1;
     //      cout << "ok" << tot << endl; 
           for (int i=n-1;i>=0;i--){
                if (reste<0){
                    reste+=v[i];
                    tot--;
                }
           }
        
           cout<<tot<<endl;
        }
    }
}  