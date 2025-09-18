#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define vi vector<int>
#define vl vector <ll>

void count_gold(vector<vector<char>>& v, vector<vector<int>>& count_goldtab, ll k, ll n, ll m, int i, int j){
   // cout<<"début\n";
    if (i==0&&j==0) return;
    if (j==0){
        count_goldtab[i][j]=count_goldtab[i-1][j];
        for (int y=0;y<k;y++){
            if (y<m&&(i+k-1<n)&&v[i+k-1][y]=='g'){
                count_goldtab[i][j]++;
            }
        }
        for (int y=0;y<k;y++){
            if (y<m&&i-k>=0&&v[i-k][y]=='g'){
                count_goldtab[i][j]--;
            }
        }
        return;
    }
    count_goldtab[i][j]=count_goldtab[i][j-1];
    for (int x=i-(k-1);x<i+k;x++){
        if (x<n&&x>=0&&(j+k-1<m)&&v[x][j+k-1]=='g'){
            count_goldtab[i][j]++;
        }
    }
    for (int x=i-(k-1);x<i+k;x++){
        if (x<n&&x>=0&&j-k>=0&&v[x][j-k]=='g'){
            count_goldtab[i][j]--;
        }
    }
    return;
}

int main(){
    int t;
    cin >> t;
    while (t--){
        ll n,m,k;
        cin>>n>>m>>k;
        vector<vector<char>> v(n,vector<char>(m));
        for (int i=0;i<n;i++){
            for (auto& x : v[i])cin>>x;
        }
        int tot_gold=0;


        vector<vector<int>> count_goldtab(n, vector<int>(m,0));
        for (int i=0;i<k;i++){
            for (int j=0;j<k;j++){
                if (i<n && j<m&&v[i][j]=='g'){
                    count_goldtab[0][0]++;
                }
            }
        }
        
        
        
        int minpertes=INT32_MAX;
        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                count_gold(v,count_goldtab, k,n,m,i,j);
                if (v[i][j]=='g'){
                    tot_gold++;
                }
                if (v[i][j]=='.'){
                    if (count_goldtab[i][j]<minpertes){
                        minpertes=count_goldtab[i][j];
                    }
                }
            }
        }
        cout<<tot_gold-minpertes<<endl;
    }
}
