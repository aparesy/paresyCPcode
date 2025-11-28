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

class Node{
public:
    char c;
    Node* prev;
    Node* next;
 
    Node(char cc,Node* p,Node* n){
        c=cc;
        prev=p;
        next=n;
    }
 
};
 
Node* del(Node* d){
    Node* p=d->prev;
    if(p) p->next=d->next;
    d->next->prev=p;
    delete d;
    return p;
}

void solve(){
    string s;
    ll pos;
    cin>>s>>pos;
    int n=s.length();
    ll curLength=n;
    Node* tab=new Node(s[0],nullptr,nullptr);
    rep(i,1,n){
        Node* tmp=new Node(s[i],tab,nullptr);
        tmp->prev->next=tmp;
        tab=tmp;
    } 
    while (tab->prev) tab=tab->prev;
    Node* cur=tab;
    while(pos>curLength){
        while ((tab->next) && (tab=tab->next) && (cur->c)<=(tab->c)){
            cur=cur->next;
        }
        cur=del(cur);
        tab=cur;
        pos-=curLength;
        curLength--;
    }
    pos--;
    while (tab->prev) tab=tab->prev;
    rep(i,0,pos){
        tab=tab->next;
    }
    cout<<(tab->c);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin>>t; rep(i,0,t)
    solve();
}