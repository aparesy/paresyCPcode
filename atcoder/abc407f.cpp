#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i=0;i<n;i++){
        cin >> v[i];
    }
    vector<int> cumMax(n,0);
    for (int i=0;i<n;i++){
        cumMax[i] = v[i];
    }
    cout << reduce(cumMax.begin(), cumMax.end()) << endl;
    for (int k=2;k*k<=n;k++){
        for (int i=0;i<n-k;i++){
            cumMax[i] = max(cumMax[i], cumMax[i+1]);
        }
        cout << reduce(cumMax.begin(), cumMax.end()-(k-1));
    }
}