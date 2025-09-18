#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define vi vector<int>
#define vl vector <ll>

int valuation(int p, ll k){
    int tot=0;
//    cout << (int)((k/p)*p) << " " << k;
    while (k>1 && (int)((k/p)*p)==k){
        k/=p;
        tot++;
    }
    return tot;
}

int main(){
//    cout << valuation(3, 72);
        int n;
        cin>>n;
        ll tab[n][n];
        int zer=-1;
        for (int i=0;i<n;i++){for(int j=0;j<n;j++){ cin>>tab[i][j];if (!tab[i][j])zer=i;}}
        pair<int,int> dp1[n][n]; // 1 : la valeur, 2 : le coup joue (0 si R,1 si D)
        dp1[0][0] = {valuation(2,tab[0][0]), -1};
        for (int i=1;i<n;i++){
            dp1[0][i]={(dp1[0][i-1]).first+valuation(2,tab[0][i]),0};
            dp1[i][0]={(dp1[i-1][0]).first+valuation(2,tab[i][0]),1};
        }
        for (int i=1;i<n;i++){
            for (int j=1;j<n;j++){
                if (dp1[i-1][j].first<dp1[i][j-1].first){
                    dp1[i][j]={(dp1[i-1][j].first)+valuation(2,tab[i][j]),1};
                }
                else dp1[i][j]={(dp1[i][j-1].first)+valuation(2,tab[i][j]),0};
            }
        }

        pair<int,int> dp[n][n];
        dp[0][0] = {valuation(5,tab[0][0]), -1};
        for (int i=1;i<n;i++){
            dp[0][i]={(dp[0][i-1]).first+valuation(5,tab[0][i]),0};
            dp[i][0]={(dp[i-1][0]).first+valuation(5,tab[i][0]),1};
        }
        for (int i=1;i<n;i++){
            for (int j=1;j<n;j++){
                if (dp[i-1][j].first<dp[i][j-1].first){
                    dp[i][j]={(dp[i-1][j].first)+valuation(5,tab[i][j]),1};
                }
                else dp[i][j]={(dp[i][j-1].first)+valuation(5,tab[i][j]),0};
            }
        }
 /**       for (int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<dp[i][j].second <<" ";
            }
            cout<<endl;
        }**/
        stack<char> s;
        if (dp[n-1][n-1].first < dp1[n-1][n-1].first){
            if (zer!=-1&&dp[n-1][n-1].first){
                cout<<1<<endl;
                for (int i=0;i<zer;i++){
                    cout<<'D';
                }
                for (int i=1;i<n;i++){
                    cout<<'R';
                }
                for (int i=zer;i<n-1;i++){
                    cout<<'D';
                }
            }
            else{cout<<dp[n-1][n-1].first<<endl;
            int i=n-1;
            int j=n-1;
            while(i>0||j>0){
                //               cout<<"i"<<i<<" j"<<j<<endl;
                if (dp[i][j].second){
                    i--;
                    s.push('D');
                }
                else{
                    j--;
                    s.push('R');
                }
            }
            while (!s.empty()){
                cout<<s.top();
                s.pop();
            }
            cout<<endl;}
        }
        else{
            if (zer!=-1&&dp[n-1][n-1].first){
                cout<<1<<endl;
                for (int i=0;i<zer;i++){
                    cout<<'D';
                }
                for (int i=1;i<n;i++){
                    cout<<'R';
                }
                for (int i=zer;i<n-1;i++){
                    cout<<'D';
                }
            }
            else{
            cout<<dp1[n-1][n-1].first<<endl;
            int i=n-1;
            int j=n-1;
            while(i>0||j>0){
                if (dp1[i][j].second){
                    i--;
                    s.push('D');
                }
                else{
                    j--;
                    s.push('R');
                }
            }
            while (!s.empty()){
                cout<<s.top();
                s.pop();
            }
            cout<<endl;      }      
        }
    }
