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
        ll n,m;
        cin>>n>>m;
        if (m>=n && n*(n+1)/2 >= m){
            ll rows=1;
            ll somme=n;
            while (somme+n-rows<=m && n-rows!=0){
                somme+=n-rows;
                rows++;
            }
            ll root=n-(m-somme)+1;
            
            if (m!=somme){
                cout<<rows+1<<endl;
                cout<<rows<<" "<<rows+1<<endl;
                if (root!=n) cout<<rows+1<<" "<<root<<endl;
                for (int i=root+1;i<n;i++){cout<<rows+1<<" "<<i<<endl;}
                for (int i=root-1;i>rows+1;i--){cout<<rows<<" "<<i<<endl;}
                cout<<rows<<" "<<n<<endl;
          //      cout<<rows<<" "<<rows+1<<endl;
            }
            if (m==somme){
                cout<<rows<<endl;
                for (int i=rows+1;i<=n;i++){
                    cout<<rows<<" "<<i<<endl;
                }
            }
            for (int i=1;i<rows;i++){
                cout<<i<<" "<<i+1<<endl;
            }
            
        }
        else cout<<-1<<endl;
    }
}