#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vl vector<ll>

// int find(vector<int>& repr, int som, int n){
//     if(repr[som] != som){
//         if (repr[repr[som]]==repr[som]){
//             return repr[som];
//         }
//         else{
//             int tmp=find(repr, repr[repr[som]], n);
//             repr[som]=tmp;
//             return tmp;
//         }
//     }
//     return som;
// }

// void join(vector<int>& repr, int som1, int som2){
//     repr[som2]=som1;
//     return;
// }
const int MAXN=7*1E3;

vector<int> lst[MAXN];
int parent[MAXN];

void make_set(int v) {
    lst[v] = vector<int>(1, v);
    parent[v] = v;
}

int find_set(int v) {
    return parent[v];
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (lst[a].size() < lst[b].size())
            swap(a, b);
        while (!lst[b].empty()) {
            int v = lst[b].back();
            lst[b].pop_back();
            parent[v] = a;
            lst[a].push_back (v);
        }
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll tmp1,tmp2;
        vl a(n);
        vl b(n);
        for (int i=0;i<n;i++){
            cin>>tmp1>>tmp2;
            a[i]=tmp1;
            b[i]=tmp2;
        }
        vector<int> ans;
//        vector<int> repr(2*n+1);
        for (int i=0;i<2*n+1;i++){
            make_set(i);
        }
        for (int i=0;i<n;i++){
            if (find_set(a[i])!= find_set(b[i])){
                union_sets(a[i],b[i]);
                ans.push_back(i);
            }
        }
        cout << ans.size() << endl;
        for (auto x : ans) cout << x+1 << " ";
        cout << endl;
    }
}