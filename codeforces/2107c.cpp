#include <bits/stdc++.h>

using namespace std;

int maxSum(vector<int>& v, int n, int i, int j){
    // faux
    vector<int> cumSum(n,0);
    cumSum[i] = v[i];
    for (int k=i+1;k<j;k++){
        cumSum[k] = cumSum[k-1]+v[k];
    }
    int curMax = 0;
    int curMin = 0;
    int curDif = 0;
    for (int k=i;k<j;k++){
        if (cumSum[k]>curMax){
            curMax = cumSum[k];
            curDif=curMax-curMin;
        }
        if (cumSum[k]<curMin) curMin=cumSum[k];
    }
    return curDif;
}

int main(){
    int t;
    cin >>t ;
    vector<int> v(3,0);
    v[0]=5;
    v[1]=-1;
    v[2]=9;
//    cout << maxSum(v,3,0,3);
    while (t--){
        int n,k;
        cin >>n>>k;
        string s;
        cin >> s;
        vector<int> v(n,0);
        int lastZ=0;
        int maxS=0;
        for (int i=0;i<n;i++){
            // Considérer la dernière somme
            cin >> v[i];
            if (v[i]==0){
                maxS=max(maxS, maxSum(v,n,lastZ,i));
                lastZ=i;
            }
        }
        maxS = max(maxS, maxSum(v,n,lastZ,n));
        if (maxS>k) cout << "no" << endl;
        else if (maxS==k){
            cout << "yes"<<endl;
            for (int i=0;i<n;i++){ 
                if (v[i]==0) cout << (-(long long) pow(10.,17.)) << " ";
                else cout << v[i] << " ";
            }
            cout << endl;
        }
        else{
            int trouve=-1;
            for (int i=0;i<n;i++){
                if (s[i]=='0'){
                    trouve=i;
                }
            }
            if (trouve==-1) cout << "no" << endl;
            else{
                cout << "yes" << endl;
                for (int i=0;i<n;i++){
                    long long tmp = -(long long) pow(10.,17.);
                    if (i==trouve) cout << k << " ";
                    else if (v[i]==0) cout << tmp << " ";
                    else cout << v[i] << " ";
                }
                cout << endl;
            }
        }
    }
}