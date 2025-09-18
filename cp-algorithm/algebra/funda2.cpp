// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long
// #define vl vector<ll>

// int main(){
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);

//    ll x=1; 
//    while(x){
//       ll y,n;
//       cin>>x>>y>>n;
//       ll tmp=x;
//       x=1;
//       while (y){
//         if (y&1){
//             x=x*tmp%n;
//         }
//         tmp=tmp*tmp%n;
//         y>>=1;
//       }    
//       cout << x<<endl;
//       x=0;
//    }
// }

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>

ll read_ll() {
    string line;
    while (getline(cin, line)) {
        if (!line.empty()) {
            return stoll(line);
        }
    }
    return 0; // End of input
}

int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(0);

   while (true) {
      ll x = read_ll();
      ll y = read_ll();
      ll n = read_ll();
      if (x == 0 && y == 0 && n == 0) break; // Optional: stop on all zeros

      ll res = 1, tmp = x;
      while (y) {
        if (y & 1) {
            res = res * tmp % n;
        }
        tmp = tmp * tmp % n;
        y >>= 1;
      }
      cout << res << endl;
   }
}