// Useful functions : nth_element, rotate, unique, merge, count, generate

#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define pdd pair<double,double>
#define vi vector<int>
#define vii vector<pii>
#define vvi vector<vector<int>>
using ll=long long;
#define vl vector<ll>
#define vvl vector<vector<ll>>
#define vb vector<bool>
#define F first 
#define S second
#define rep(i,a,b) for(int i=a;i<b;i++)
#define input(tab) for (auto& x : tab)cin>>x
#define all(x) x.begin(),x.end()

ll get(){
   ll x;
   cin>>x;
   return x;
}

void solve(){
    int n=get();
    string s;
    cin>>s;
    vi delta(n);
    char prev='X';
    int i=0;
    while (i<n){
        int j=i;
        vector<char> tmp;
        tmp.push_back(prev);
        while (j<n-1 && s[j+1]==s[i]){
            prev=s[j];
            j++;
            tmp.push_back(prev);
        }
        for(int k=0;k<tmp.size();k++){
            char c=tmp[k];
            if (s[i]=='L'){
                if (c=='X'){
                    delta[tmp.size()]++;
                }
                else if (c=='R'){
                    delta[tmp.size()]++;
                }
                else{
                    delta[tmp.size()-k]++;
                    delta[n-k-1]--;
                }
            }
            else{
                if (c=='R'){
                    delta[k]++;
                    delta[n-tmp.size()-k]--; //jsp
                }
                else{
                    delta[n-tmp.size()-1]++;
                }
            }
        }
        i=j+1;
        prev=s[j];
    }
    ll cumSum=0;
    rep(i,0,n){
        cumSum+=delta[i];
        cout<<cumSum<<" ";
    }
    cout<<"\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin>>t; rep(i,0,t)
    solve();
}