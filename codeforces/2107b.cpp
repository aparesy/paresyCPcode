#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define vi vector<int>
#define vl vector <ll>

int main(){
    int t;
    cin >> t;
    while (t--){
        ll n,k;
        cin >>n>>k;
        vl a(n);
        for (auto& x : a) cin >> x;
        ll maxi = 0;
        ll mini = a[0];
        int nbmaxi=1;
        for (int i=0;i<n;i++){
            if (a[i] == maxi) nbmaxi++;
            if (a[i]>maxi){ maxi=a[i]; nbmaxi=1;}
            if (a[i] < mini) mini=a[i];
        }
     //   cout << (maxi-mini>=k+2);
        if (maxi-mini>=k+2 ||((nbmaxi>=2) && (maxi-mini==k+1)) ||(reduce(a.begin(), a.end())%2==0)) cout << "Jerry"; else cout << "Tom";
        cout << endl;   
    }
}