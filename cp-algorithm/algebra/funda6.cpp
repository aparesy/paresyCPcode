#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>

vector<int> apply_perm(vector<int>& op, vector<int>& perm){
    vector<int> tmp = perm;
    for (int i=0;i<op.size();i++){
        tmp[i]=perm[op[i]-1]; // op et perm entre 1 et n
    }
    return tmp;
}

void test1(){
    vector<int> op = {3,1,2,4};
    vector<int> perm= {4,1,2,3};
    vector<int> res=apply_perm(op,perm);
    for (int i=0;i<4;i++){
        cout<<res[i]<<" ";
    }
    cout<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll k;cin>>k;
        vector<int> perm(n,0);
        for (int  i=0;i<n;i++){
            perm[i]=i+1;
        }
        vector<int> op(n,0);
        for (int i=0;i<n;i++){
            op[i]=2*i+1-(2*i>=n?n-1:0);
          //  cout << op[i] << " ";
        }
        while(k){
            if (k&1){
                perm=apply_perm(perm,op);
            }
            op=apply_perm(op,op);
            k>>=1;
        }
        for (int i=0;i<n;i++){
            cout<<perm[i]<< " ";
        }
        cout<<endl;
    }
}