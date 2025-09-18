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

        // vector<int> puissQuatre;
        // for (int i=0;i*i*i*i<=n;i++){
        //     puissQuatre.push_back(i*i*i*i);
        // }
        
        // const int S = 10000;

        vector<int> primes;
        int nsqrt = sqrt(n);
        vector<char> is_prime(nsqrt + 2, true);
        for (int i = 2; i <= nsqrt; i++) {
            if (is_prime[i]) {
                primes.push_back(i);
                for (int j = i * i; j <= nsqrt; j += i)
                    is_prime[j] = false;
            }
        }

        int result = 0;
        // vector<char> block(S);
        // for (int k = 0; k * S <= n; k++) {
        //     fill(block.begin(), block.end(), true);
        //     int start = k * S;
        //     for (int p : primes) {
        //         int start_idx = (start + p - 1) / p;
        //         int j = max(start_idx, p) * p - start;
        //         for (; j < S; j += p)
        //             block[j] = false;
        //     }
        //     if (k == 0)
        //         block[0] = block[1] = false;
        //     for (int i = 0; i < S && start + i <= n; i++) {
        //         if (block[i]){
        //             for (auto y : puissQuatre){
        //                 if (y>=i+S*k) break;
        //                 int x=sqrt(i+S*k-y);
        //                 if (x*x==(i+S*k-y)){
        //                     result++;
        //                     break;
        //                 }
        //             }
        //         }
        //     }
        // }
        // cout<<result<<"\n";
        bool ok = true;
        for (int y=1; y*y*y*y<=n;y++){
            int tmp=y*y*y*y;
            for (int x=1; x*x<=n-tmp; x++){
                ok=true;
                for (auto z : primes){
                    if ((tmp+x*x)%z==0){
                        if (tmp+x*x==z) break;
                        ok=false;
                    }
                }
                if (ok) result++;
            }
        }
        cout<<result<<"\n";
    }
}

