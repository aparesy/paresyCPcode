#include <iostream>
#include <vector>
#define ll long long
using namespace std;

int main(){
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        vector<ll> v(n,0);
        for (int i=0;i<n;i++) cin >> v[i];
        int tot=1;
        int desc=false;
        for (int i=1;i<n;i++){
            if (desc){
                if (v[i]<=v[i-1]) continue;
                tot++;
                desc=false;
            }
            else{
                if (v[i]>=v[i-1]) continue;
                desc=true;
            }
        }
        cout << tot << endl;
    }
}