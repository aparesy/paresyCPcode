#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define vi vector<int>
#define vl vector <ll>

int main(){
    int n;
    cin>>n;
    int q;
    cin>>q;
    vl v(q);
    for (auto& x : v)cin>>x;
    vl box(n,0);
    for (int i=0;i<q;i++){
        if (v[i]>0){
            cout<<v[i]<<" ";
            box[v[i]-1]++;
        }
        else{
            int mini = *min_element(box.begin(), box.end());
            bool trouve=false;
            for (int j=0;j<n&&!trouve;j++){
                if (box[j]==mini){
                    trouve=true;
                    cout<<j+1<<" ";
                    box[j]++;
                }
            }
        }
    }
}