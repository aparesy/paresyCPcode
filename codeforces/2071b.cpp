#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define vi vector<int>
#define vl vector <ll>

bool isSq(double x){
    return floor(sqrt(x))==ceil(sqrt(x));
}

int main(){
    int t;
    cin >> t;
    while (t--){
        ll n;
        cin>>n;
        if (isSq((double)(n*(n+1)/2))) cout <<-1<<endl;
        else{
            ll s=0;
            stack<ll> s1;
            stack<ll> s2;
            for (int i=1;i<=n;i++) s1.push(n-i+1);
            for (int i=0;i<n;i++){
                while (!s1.empty() && isSq(s+s1.top())){
                    s2.push(s1.top());
                    s1.pop();
                }
                cout << s1.top() << " ";
                s+=s1.top();
                s1.pop();
                while (!s2.empty()){
                    s1.push(s2.top());
                    s2.pop();
                }
            }
            cout << endl;
        }
    }
}