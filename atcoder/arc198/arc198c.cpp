#include <bits/stdc++.h>
using namespace std;

void pivot0(int iP, int iG, vector<int>& a, vector<int>& b){
 //   cout << "what";
    if (iP<iG){
        cout << iP+1 << " " << iG+1 << endl;
        cout << 1 << " " << iG+1 << endl;
        cout << 1 << " " << iP+1 << endl;
        cout << 1 << " " << iG+1 << endl;
    }
    else{
        cout << 1 << " " << iP+1 << endl;
        cout << 1 << " " << iG+1 << endl;
        cout << 1 << " " << iP+1 << endl;
        cout << iG+1 << " " << iP+1 << endl;
    }
    a[iP]++;
    a[iG]--;
}

void pivotn(int n, int iP, int iG, vector<int>& a, vector<int>& b){
    if (iP<iG){
        cout << 1 << " " << iG+1 << endl;
        cout << iG+1 << " " << n << endl;
        cout << 1 << " " << n << endl;
        cout << iG+1 << " " << n << endl;
    }
    else{
        cout << iP+1 << " " << n << endl;
        cout << 1 << " " << n << endl;
        cout << iP+1 << " " << n << endl;
        cout << 1 << " " << iP+1 << endl;
    }
    a[iP]++;
    a[iG]--;
}

void pivot1(int n, int iP, int iG, vector<int>& a, vector<int>& b){
    if (iP<iG){
        cout << 1 << " " << 2 << endl;
        cout << 2 << " " << n << endl;
        cout << 1 << " " << 2 << endl;
        cout << 1 << " " << n << endl;
    }
    else{
        cout << 1 << " " << n << endl;
        cout << 1 << " " << 2 << endl;
        cout << 2 << " " << n << endl;
        cout << 1 << " " << 2 << endl;
    }
    a[iP]++;
    a[iG]--;
}


int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    for (auto& x : a) cin >> x;
    for (auto& x : b) cin >> x;
    vector<int> c=a;
    vector<int> d=b;
    if (n==2){
        if (a[0] == b[0] && a[1] == b[1]){
            cout << "Yes" << endl;
            cout << 0 << endl;
        }
        else if (a[0] == b[1]-1 && a[1] == b[0]+1){
            cout << "Yes" << endl;
            cout << 1 << endl;
            cout << 1 << " " << 2 << endl;
        }
        else cout << "No" << endl;
    }
    else if (reduce(a.begin(), a.end())==reduce(b.begin(), b.end())){
        cout << "Yes" << endl;
        int count=0;
        int iP=0;
        int iG=0;
        while(iP<n && a[iP] >= b[iP]){
            iP++;
        }
        while(iG<n && a[iG] <=b[iG]){
            iG++;
        }
        while(iP<n && iG<n){
            while (c[iP] < d[iP] && c[iG]>d[iG]){
                c[iP]++;
                d[iG]--;
                count+=4;
            }
            while(iP<n && c[iP] >= d[iP]){
                iP++;
            }
            while(iG<n && c[iG] <=d[iG]){
                iG++;
            }
        }
        cout << count << endl;
        iP=0;
        iG=0;
        while(iP<n && a[iP] >= b[iP]){
            iP++;
        }
        while(iG<n && a[iG] <=b[iG]){
            iG++;
        }
        while(iP<n && iG<n){
            while (a[iP] < b[iP] && a[iG]>b[iG]){
    //            cout << iP << " " << iG << endl << endl;
                if ((iP==0 && iG==n-1) || (iG==0 && iP==n-1)) pivot1(n, iP, iG, a, b);
                else if (iP==0 ||iG==0) pivotn(n, iP, iG, a, b);
                else pivot0(iP, iG, a, b);
            }
            while(iP<n && a[iP] >= b[iP]){
                iP++;
            }
            while(iG<n && a[iG] <=b[iG]){
                iG++;
            }
        }
    }
    else{
        cout << "No" << endl;
    }
}