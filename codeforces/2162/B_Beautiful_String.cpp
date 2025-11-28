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
    vi tab(n);
    string s;
    cin>>s;
    rep(i,0,n){
        tab[i]=s[i]-'0';
    }
    rep(i,0,n){
        if (tab[i]!=tab[n-1-i]) break;
        if (i==n-1){
            cout<<0<<"\n\n";
            return;
        }
    }
    // rep(i,0,n){
    //     if (i) tab[i-1]=s[i-1];
    //     rep(j,i,n){
    //         tab[i]=s[i];
    //     }
    //     int maxi=0;
    //     rep(j,i,n){
    //         if (tab[j]>=maxi){
    //             maxi=tab[j];
    //             tab[j]=-1;
    //             int left=0;
    //             int right=n-1;
    //             while(left<n && right>=0){
    //                 while(tab[left]==-1 && left<n)left++;
    //                 while(tab[right]==-1 && right>=0)right--;
    //                 if (tab[left]!=tab[right]){
    //                     break;
    //                 }
    //                 else if (left<=right){
    //                     left++;
    //                     right--;
    //                 }
    //                 else{
    //                     cout<<j-i+1<<"\n";
    //                     rep(l,0,n){
    //                         if (tab[l]==-1)cout<<l+1<<" ";
    //                     }
    //                     cout<<"\n";
    //                     return;
    //                 }
    //             }
    //         }
    //         else{
    //             break;
    //         }
    //     }
    // }
    // cout<<-1<<"\n";

    rep(bitmask,0,(1<<n)){
        // on retire le bitmask
        bool ok=true;
        rep(j,0,n){
            rep(k,j+1,n){if (!((bitmask>>j)&1) && (!((bitmask>>k)&1)) && tab[k]<tab[j])ok=false;}
        }
        if (ok){
            queue<int> q;
            stack<int> s;
            rep(k,0,n){
                if ((bitmask>>k)&1){
                    q.push(tab[k]);
                    s.push(tab[k]);
                }
            }
            while (!q.empty()){
                if (q.front()!=s.top()) ok=false;
                q.pop();
                s.pop();
            }
        }
        if (ok){
            int tot=0;
            rep(i,0,n){
                if (!((bitmask>>i)&1))tot++;
            }
            cout<<tot<<"\n";
            rep(l,0,n){
                if (!((bitmask>>l)&1))cout<<l+1<<" ";
            }
            cout<<"\n";
            return;
        }

    }
    cout<<"-1\n";

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin>>t; rep(i,0,t)
    solve();
}