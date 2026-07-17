#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define vi vector<int>
#define vl vector <ll>


int main(){
    int t;
    cin >> t;
    while (t--){
        int n;
        cin>>n;
        vl v(n);
        for (auto& x : v) cin>>x;
        int i=0;
        bool fini=false;
        while(!fini){
            bool count0=false;
            bool count1=false;
            for (auto x : v){
                if (x&(1<<i)){
                    count1=true;
                }
                else count0=true;
            }
            if (count0&&count1){
                fini=true;
            }
            i++;
        }
        cout<<(1<<i)<<endl;
    }
}
