#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define vi vector<int>
#define vl vector <ll>
vector<int> read_ints(int n) { vector<int> v(n); for (auto& x : v) cin >> x; return v; }
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define loop(n) for(int i=0;i<n;i++)

bool isSquare(ll x){
    ll y =sqrt(x);
    if (y*y==x){
        return true;
    }
    return false;
}

int main(){
    int t;
    cin >> t;
    while (t--){
        ll l1,b1,l2,b2,l3,b3;
        cin>>l1>>b1>>l2>>b2>>l3>>b3;
        ll area=l1*b1+l2*b2+l3*b3;
        bool fini=false;
        if (isSquare(area)){
            ll c = sqrt(area);
            if (l1==c){
                if (l2==c){
                    if (l3==c&&b2+b3+b1==c){
                        fini=true;
                    }
                }
                else if (l2+l3==c){
                    fini=true;
                }
            }
            else if (b1==c){
                if (b2==c){
                    if (b3==c&&l1+l2+l3==c){
                        fini=true;
                    }
                }
                else if (b2+b3==c){
                    fini=true;
                }
            }
        }
        if (fini)cout<<"YES"; else cout<<"NO";
        cout<<endl;
    }
}