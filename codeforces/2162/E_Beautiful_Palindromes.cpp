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
    int n,k;
    cin>>n>>k;
    vi tab(n);
    input(tab);
    set<int> doesNotAppear;
    rep(i,0,n){
        doesNotAppear.insert(i+1);
    }
    unordered_map<int,int> vu;
    for (auto x : tab){
        doesNotAppear.erase(x);
        vu[x]++;
    }
    auto it=doesNotAppear.begin();
    if (doesNotAppear.size()==0){
        if (n==2 && k==2){
            cout<<tab[1]<<" "<<tab[0]<<"\n";
            return;
        }
        if (n==2 && k==1){
            cout<<tab[1]<<"\n";
            return;
        }
        rep(i,0,k){
            cout<<tab[i]<<" ";
        }
        cout<<"\n";
        return;
    }
    if (doesNotAppear.size()==1){
        if (k==1){
            cout<<*it;
        }
        else{
            cout<<*it<<" ";
            rep(i,0,n){
                if (i+1!=*it && i+1!=tab[n-1]){
                    cout<<i+1<<" ";
                    vu[i+1]+=2;
                    break;
                }
            }
            int tot=0;
            rep(i,0,n){
                if (vu[tab[i]]==1 && tot<k-2){
                    cout<<tab[i]<<" ";
                    tot++;
                }
            }
            if (tot<k-2){
                rep(i,0,n){
                    if (vu[i+1]==2){
                        cout<<i+1<<" ";
                        break;
                    }
                }
            }
        }
        cout<<"\n";
        return;
    }
    int x=*it;
    int y;
    cout<<*it<<" ";
    if (k!=1){
        it++;
        y=*it;
        cout<<*it<<" ";
    }
    int tot=1;
    rep(i,0,k-2){
        if (tot==x || tot==y) tot++;
        if (tot==x || tot==y) tot++;
        cout<<tot<<" ";
        tot++;
    }
    cout<<"\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin>>t; rep(i,0,t)
    solve();
}