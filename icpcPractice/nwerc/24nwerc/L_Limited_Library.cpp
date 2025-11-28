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
    int n,m,x,y;
    cin>>n>>m>>x>>y;
    vl heightShelf(n);
    input(heightShelf);
    vl heightBook(m);
    input(heightBook);
    // Binary search on the maximum amount of art pieces you can fit, first insert the art pieces then the books, look if there are leftover books at the end
    sort(all(heightBook));
    sort(all(heightShelf));
    int i=0;
    int j=0;
    vi filling(n);
    while (i<n){
        // Fit books on shelves
        while (j<m && filling[i]<x && heightBook[j]<=heightShelf[i]){
            j++;
            filling[i]++;
        }
        i++;
    }
    if (j!=m){
        cout<<"impossible";
        return;
    }
    int l=0;
    int r=n+1;
    while(r-l>1){
        fill(all(filling), 0);
        int mid=(r+l)/2;
        // Of course you fit them on the lowest shelves
        i=0;
        j=0;
        while (i<n){
        // Fit books on shelves
            while (j<m && ((i<mid)?(filling[i]<y):(filling[i]<x)) && heightBook[j]<=heightShelf[i]){
                j++;
                filling[i]++;
            }
            i++;
        }
        if (j!=m){
            r=mid;
        }
        else l=mid;
    }
    cout<<l;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
}