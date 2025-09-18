#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    if (n==1) cout << 1 << endl << 1;
    else{

    
    if (n%2==1 && n>=7) n-=1;
    cout << n/2 << endl;
    if (n%2){
        for (int i=3;i<=n;i+=2) cout << i <<  " ";
    }
    else for (int i=2;i<=n;i+=2) cout << i << " ";

}
}