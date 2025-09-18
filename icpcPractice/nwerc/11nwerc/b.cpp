#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define pdd pair<double,double>
#define vi vector<int>
#define vii vector<pii>
#define vvi vector<vector<int>>
#define ll long long
#define vl vector<ll>
#define vvl vector<vector<ll>>
#define rep(i,a,b) for(int i=a;i<b;i++)

void solve(){
    ll a,b;
    string s;
    cin>>s;
    a=stoi(s.substr(0,s.find('/')));
    b=stoi(s.substr(s.find('/')+1, s.size()));
    deque<char> q;
    while(a!=b){
        if (a<b){
            q.push_back('L');
            swap(a,b);
            a-=b;
        }
        else{
            q.push_back('R');
            a-=b;
            swap(a,b);
        }
    }
    while (!q.empty()){
        cout<<q.front();
        q.pop_front();
    }
    cout<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    rep(i,0,t)
    solve();
}