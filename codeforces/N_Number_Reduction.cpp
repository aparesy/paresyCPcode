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
    string s;
    cin>>s;
    int n=s.length();
    int k=get();
    deque<char> deq;
    int totRemoved=0;
    int i=0;
    while(i<n){

        if (s[i]=='0' && !deq.size()){totRemoved++; i++; continue;}
        if (s[i]=='0' && deq.size()==1){
            int curL=deq.back();
            int tot=0;
            while(i<n && s[i]=='0'){
                i++;
                tot++;
            }
            if (i!=n && s[i]<curL && totRemoved+tot<k){
                deq.pop_back();
                totRemoved+=(tot+1);
            }
            else{
                rep(j,0,tot){
                    deq.push_back('0');
                }
            }
        }
        while(deq.size() && deq.back() > s[i] && totRemoved<k){
            if (s[i]=='0' && deq.size()==1) break;
            totRemoved++;
            deq.pop_back();
        }
        deq.push_back(s[i]);

        i++;
    }
    while(totRemoved<k){
        deq.pop_back();
        totRemoved++;
    }
    while (!deq.empty()){
        cout<<(deq.front());
        deq.pop_front();
    }
    cout<<"\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin>>t; rep(i,0,t)
    solve();
}