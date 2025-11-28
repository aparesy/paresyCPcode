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
    int n;
    cin>>n;
    vi a(n);
    vi b(n);
    input(a);
    input(b);
    int cont=0;
    rep(i,0,n){
        if( a[i]%2){
            cont++;
        }
    }
    if (cont<=n-2){
        cout<<0<<"\n";
        return;
    }

    set<ll> premiersVus;

    if (cont==n-1){
        // Déterminer s'il existe deux entiers non premiers entre eux   . Décomposition en sqrt(a) = 100
        rep(i,0,n){
            set<ll> curFact;
            int tmp=a[i];
            while (tmp>1){
                bool trouve=false;
                for (int i=2; i*i<=tmp && !trouve; i++){
                    if (tmp%i == 0){
                        tmp/=i;
                        curFact.insert(i);
                        trouve=true;
                    }
                }
                if (!trouve){
                    curFact.insert(tmp);
                    tmp=1;
                }
            }
            for (auto x : curFact){
                if (premiersVus.count(x)){
                    cout<<0<<"\n";
                    return;
                }
                else premiersVus.insert(x);
            }
        }
        cout<<1<<"\n";
        return;
    }
    else{
        // Sinon ils sont tous impairs. On peut vérifier facilement s'ils sont premiers entre eux. Pour chaque élément il s'agit d'incémenter et de voir dans les facteurs
        rep(i,0,n){
            set<ll> curFact;
            int tmp=a[i];
            while (tmp>1){
                bool trouve=false;
                for (int i=2; i*i<=tmp && !trouve; i++){
                    if (tmp%i == 0){
                        tmp/=i;
                        curFact.insert(i);
                        trouve=true;
                    }
                }
                if (!trouve){
                    curFact.insert(tmp);
                    tmp=1;
                }
            }
            for (auto x : curFact){
                if (premiersVus.count(x)){
                    cout<<0<<"\n";
                    return;
                }
                else premiersVus.insert(x);
            }
        }

        rep(i,0,n){
            int tmp=a[i]+1;
            while (tmp>1){
                bool trouve=false;
                for (int i=2; i*i<=tmp && !trouve; i++){
                    if (tmp%i == 0){
                        tmp/=i;
                        if (premiersVus.count(i)){
                            cout<<1<<"\n";
                            return;
                        }
                        trouve=true;
                    }
                }
                if (!trouve){
                    if (premiersVus.count(tmp)){
                        cout<<1<<"\n";
                        return;
                    }
                    tmp=1;
                }
            }
        }
        cout<<"2\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin>>t; rep(i,0,t)
    solve();
}