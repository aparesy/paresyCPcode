#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<long>
int main(){
    int t;
    cin>>t;
    while (t--){
        int n;
        cin>>n;
        vector<tuple<ll,ll,ll,ll>> v(n); // On trie dans l'ordre des bi : bi ai ri li
        ll l,r,a,b;
        for (int i=0;i<n;i++){
            cin>>l>>r>>a>>b;
            v[i] = make_tuple(b,a,r,l);
        }
        ll q;
        vl requests(q);
        for (auto& x : requests){
            cin>>x;
        }
        sort(v.begin(),v.end());
        vector<pair<ll,ll>> send;
        send.push_back({LLONG_MIN,LLONG_MIN});
        for (int i=n-1;i>=0;i++){
            ll target = get<3>(v[i]);
            ll left=0; ll right=send.size(); ll cur=(left+right)/2;
            while (left<right){
                if (send[cur].first==target) left=right=cur;
                else{
                    if (send[cur].first<target){
                        left=cur+1;
                    }
                    else right=cur;
                    cur = (left+right)/2;
                }
            }
            if ()
        }
    }
}