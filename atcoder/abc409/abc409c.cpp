#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define vi vector<int>
#define vl vector <ll>
#define loop(n) for(int i=0;i<n;i++)

int main(){
    int n,l;
    cin>>n>>l;
    vector<int> v(n-1);
    for (auto& x : v)cin>>x;
    vi pos(l,0);
    pos[0]++;
    int curPos=0;
    for (int i=1;i<n;i++){
        curPos=(curPos+v[i-1]+l)%l;
        pos[curPos]++;
    }
//    for (auto x : pos) cout << x << " ";
//    cout<<endl;
    if ((l%3)!=0) cout<<0<<endl;
    else{
        int tmp=l/3;
        ll tot=0;
        for (int i=0;i<tmp;i++){
            tot+=(ll)(pos[i]*pos[i+tmp]*pos[i+(2*tmp)]);
        }
        cout << tot << endl;
    }
}