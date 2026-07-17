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

// When is s of shift distance 1 from an alternating string ? In a very particular configuration. I guess that's still one less character to remove

void solve(){
    int n=get();
    string s;
    cin>>s;
    int mini;
    vi occEven(50), occOdd(50);
    rep(i,0,n){
        if (i%2){
            occOdd[s[i]-'a']++;
        }
        else occEven[s[i]-'a']++;
    }
    sort(all(occEven)); sort(all(occOdd));
    if ((n%2)==0){
        mini= n -occEven.back() - occOdd.back();
        cout<<mini<<"\n";
        return;
    }

    mini=n;
    fill(all(occEven),0);
    fill(all(occOdd),0);
    rep(i,1,n){
        if (i%2){
            occOdd[s[i]-'a']++;
        }
        else occEven[s[i]-'a']++;
    }
    mini=min(mini, n-(*max_element(all(occEven))) -(*max_element(all(occOdd))));
    rep(i,1,n){
        if (i%2){
            occOdd[s[i]-'a']--;
        }
        else occEven[s[i]-'a']--;

        if (i%2){
            occOdd[s[i-1]-'a']++;
        }
        else occEven[s[i-1]-'a']++;

        mini=min(mini, 1+ n-1-(*max_element(all(occEven))) -(*max_element(all(occOdd))));
    }

    cout<<mini<<"\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin>>t; rep(i,0,t)
    solve();
}