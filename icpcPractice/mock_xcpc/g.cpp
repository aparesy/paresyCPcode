#include <bits/stdc++.h>
using namespace std;
    
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
    
    
void takeInput(vi& zoneA, int n)
{
    int counter = 0;
    char last = 'a';
    for(int i = 0; i < n; i++)
    {
        char c;
        cin >> c;
        if(last != 'a' && c != last)
        {
            zoneA.push_back(counter);
            counter = 0;
        }
        else if(last == 'a' && c == '1')
        {
            zoneA.push_back(0);
        }
        counter++;
        last = c;
    }
    if(counter > 0)
        zoneA.push_back(counter);
}
    
int n, m;
bool solve()
{
    cin >> n >> m;
    vector<int> zoneA;
    vector<int> zoneB;
    
    takeInput(zoneA, n);
    takeInput(zoneB, m);
    
    // for(int i : zoneA)
    //     cout << i << " ";
    // cout << endl;
    // for(int i : zoneB)
    //     cout << i << " ";
    if (n<m) return false;
    // cout << endl << "\n"; 
    n = zoneA.size();
    m = zoneB.size();
    if (m==0) return false;
    if ((m%2==0) && (n%2==1)) return false;

    int i=0;
    int j=0;
    while (j<m){
        if (j%2){
            while(((i%2)==0)||(i<n && zoneA[i]<zoneB[j])) i++;
            if (i>=n) return false;
        }         
        else{
            // We are checking the zeros on bottom
            if (zoneB[j]==0){j++; continue;}
            if (i%2) i++;
            if (i==0 && zoneA[0]==0) i=2;
            if (i>=n) return false;


            int tot0=zoneA[i];
            while (tot0<zoneB[j] && i+2<n){
                i+=2;
                tot0+=zoneA[i];
            }
            if (tot0<zoneB[j] && i>=n-2) return false;
        }  
        j++;
    }
    if ((m%2)==0){
        int maxi=zoneA[n-1];

        if (maxi<zoneB[m-1]) return false;
    }

    return true;
}
    
int main() {
    
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    
    int t;
    
    cin >> t;
    for(int i = 0; i < t; i++)
    {
        if(solve())
            cout << "yes\n";
        else    
            cout << "no\n";
    }
    
    
}