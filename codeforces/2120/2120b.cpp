#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define vi vector<int>
#define vl vector <ll>
vector<int> read_ints(int n) { vector<int> v(n); for (auto& x : v) cin >> x; return v; }
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define loop(n) for(int i=0;i<n;i++)

int main(){
    int t;
    cin >> t;
    while (t--){
        ll n,s;
        cin>>n>>s;
        ll count=0;
        for (int i=0;i<n;i++){
            ll a,b,c,d;
            cin>>a>>b>>c>>d;
            if (c==d && a==b){
                count++;
            }
            else if (c==s-d && a!=b){
                count++;
            }
        }
        cout<<count<<endl;  
    }
}