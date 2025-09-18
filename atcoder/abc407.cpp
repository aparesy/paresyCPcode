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
    int chosenOne = sqrt((double)n)/2.;
    vector<int> sample(n,0);
    int k=1;
    while (k*k<=n){
        for (int i=0;i<n-k;i++){
            cumMax[i] = max(cumMax[i], cumMax[i+1]);
        }
        cout << reduce(cumMax.begin(), cumMax.end()-k) << endl;
        if (k==chosenOne){
            for (int i=0;i<n;i++){
                sample[i] = cumMax[i];
            }
        }
        k++;
    }
    while(k<n){
        cumMax[0] = max(cumMax[0], v[k]);
        int tot=cumMax[0]*;

    }

}