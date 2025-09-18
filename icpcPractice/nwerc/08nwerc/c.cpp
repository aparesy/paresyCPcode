    #include <bits/stdc++.h>
    using namespace std;
    #define ll long long
    #define vl vector<ll>

    int int_of_animal(string s, int c){
        return s[1]-'1'+(s[0]=='D'?c:0);
    }

    bool try_kuhn(int v, vector<bool>& vu, vector<int>& mt, vector<vector<int>>& adj){
        if (vu[v]) return false;
        vu[v]=true;
        for (auto neighb : adj[v]){
            if (mt[neighb]==-2 || try_kuhn(mt[neighb],vu,mt,adj)){
                mt[neighb]=v;
                return true;
            }
        }
        return false;
    }

    int main(){
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        int t;
        cin>>t;
        while(t--){
            int c,d,v; string s;
            cin>>c>>d>>v; //1,...,c,c+1,...c+d-1
            vector<vector<int>> adj(v);
            vector<int> loves(v,-1);
            vector<int> hates(v,-1);    
            for (int i=0;i<v;i++){
                cin>>s;
                loves[i]=int_of_animal(s,c);
                cin>>s;
                hates[i]=int_of_animal(s,c);
                for (int j=0;j<i;j++){
                    if (hates[j]==loves[i]){
                        adj[i].push_back(j);
                        adj[j].push_back(i);
                    }
                    else if (hates[i]==loves[j]){
                        adj[i].push_back(j);
                        adj[j].push_back(i);
                    }
                }
            }
            vector<int> mt(v,-2);
            vector<bool> vu(v,false);
            for (int i=0;i<v;i++){
                if (loves[i]<c){
                vu.assign(v,false);
                try_kuhn(i,vu,mt,adj);
                }
            }
            int tot=0;
            for (int i=0;i<v;i++){
                if (mt[i]!=-2) tot++;
            }
            cout<<v-tot<<endl;
        }
    }