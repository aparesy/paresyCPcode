#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define vi vector<int>
#define vl vector <ll>
#define loop(n) for(int i=0;i<n;i++)

int main(){
    int t;
    cin >> t;
    while (t--){
        int n;
        cin>>n;
        vl a(n);
        for (auto& x : a)cin>>x;
        vl b(n);
        for (auto& x : b)cin>>x;
        int i=0;
        int j=0;
        int points=0;
        int lastloss=-1;
        int losspos=0;
        for (int k=0;k<n;k++){
            if (a[i]>b[j]){
                points++;
                i++;
            }
            else{
                j++;
                lastloss=i;
                losspos=k;
            }
        }
        if (losspos!=n-1){
            if (lastloss!=-1){
                int maxi=a[i+1];
                int max_ind=i+1;
                for (int apres=i+1;apres<n;apres++){
                    if (a[apres]>maxi){
                        maxi=a[apres];
                        max_ind=apres;
                    }
                }
                if (maxi>a[lastloss]){
                    a[max_ind]=a[lastloss];
                    a[lastloss]=maxi;
                    i=0;
                    j=0;
                    points=0;
                    for (int k=0;k<n;k++){
                        if (a[i]>b[j]){
                            points++;
                            i++;
                        }
                        else j++;
                    }
                }
            }
        }
        else{
            
        }
        cout<<points<<endl;
    }
}