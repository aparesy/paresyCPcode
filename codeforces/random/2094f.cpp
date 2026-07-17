#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
    long long n,m;
    long long k;
    cin >> m>>n>>k;
    if (m%k==0 && n%k==0){
        for (int i=0;i<m;i++){
            for (int j=0;j<n;j++){
                cout << (i+j)%k +1 << " ";
            }
            cout << endl;
        }
    }
    else{
        if (n%k!=0){
            for (int i=0;i<n*m;i++){
                cout << i%k +1<< " ";
                if (i%n==n-1) cout <<endl;
            }
        }
        else{
            for (long long i=0; i<n*m;i++){
                int lgn = i/n;
                int col = i%n;
                cout << (col*m+lgn)%k +1<< " ";
                if (i%n==n-1) cout << endl;
            }
        }
    }
}
}