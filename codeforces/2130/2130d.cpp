#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vl tab(n);
        for (auto& x : tab) cin>>x;
        // vector<int> cnt(n,0);
        // for (int i=0;i<n;i++){
        //     for (int j=0;j<i;j++){
        //         if (tab[j] < tab[i]){
        //             cnt[i]++;
        //         }
        //     }
        // }
        vector<int> changer(n,0);
        int count;
        for (int i=n-1;i>=0;i--){
            count=0;
            for (int j=0;j<i;j++){
                if (tab[j]>tab[i]) count++;
            }
            for (int j=i+1;j<n;j++){
                if (changer[j] && tab[i]<tab[j]){
                    count--;
                }
                else if (!changer[j]){
                    count--;
                }
                else 
            }
            if (count>=0){
                changer[i]=1;
            }
        }
        for (int i=0;i<n;i++){
            tab[i]=changer[i]?2*n-tab[i]:tab[i];
  //          cout << tab[i] << " ";
        }
 //       cout<<endl;
        ll tot=0LL;
        for (int i=0;i<n;i++){
            for (int j=0;j<i;j++){
                if (tab[j]>tab[i]){
                    tot++;
                }
            }
        }
        cout<<tot<<endl;
    }
}