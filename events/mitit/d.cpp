#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for (int i = 0; i < n; i++) 

struct Node {
    int cnt = 0;
    int best = 0;
    Node* ch[2] = {nullptr,nullptr};
};

int K;

void update_best(Node* node){
    int left = node->ch[0] ? node->ch[0]->best : INT_MIN;
    int right = node->ch[1] ? node->ch[1]->best : INT_MIN;
    node->best = node->cnt + max(left,right);
}

void add(Node* node, int x, int depth, int val){
    node->cnt += val;
    if(depth == K){
        node->best = (node->cnt>0 ? INT_MIN : 0);
        return;
    }

    int bit = (x>>depth)&1;

    if(!node->ch[bit]) node->ch[bit] = new Node();
    if(!node->ch[bit^1]) node->ch[bit^1] = new Node();

    add(node->ch[bit], x, depth+1, val);
    update_best(node);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    forn(kkk,t){
        int N,Q;
        cin>>N>>Q>>K;

        vector<int>a(N);
        Node* root = new Node();

        for(int i=0;i<N;i++){
            cin>>a[i];
            add(root,a[i],0,1);
        }

        cout<<root->best<<"\n";

        while(Q--){
            int i,v;
            cin>>i>>v;
            --i;

            add(root,a[i],0,-1);
            a[i]=v;
            add(root,a[i],0,1);

            cout<<root->best<<"\n";
        }
    }
}