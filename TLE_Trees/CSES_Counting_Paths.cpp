/*Utkarsh Sahay*/
#include <bits/stdc++.h>
using namespace std;

void dfs(int node, int par,vector<int> adj[],bool &A, bool &B, int a, int b,vector<int> &ans){
    if(node == a) A = true;
    if(node == b) B = true;
    if(A & B){
        ans[a]++;
        ans[b]++;
    }

    for(auto it : adj[node]){
        if(it == par) continue;
        dfs(it,node,adj,A,B,a,b,ans);
    }

    if(node == a) A = false;
    if(node == b) B = false;
}
void solve(){
    int n,q;
    cin>>n>>q;
    vector<int> adj[n+1];
    vector<int> ans(n+1,0);
    bool A,B;

    for(int i = 0;i < n-1; i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i = 0;i < q; i++){
        int a , b;
        cin >> a >> b;
        dfs(1,0,adj,A,B,a,b,ans);
        for(int i = 1; i < ans.size(); i++) cout<<ans[i]<<" ";
    }
}
 
int main(){

    int t;
    cin >> t;
    while(t--){
        solve();
    }
 
    return 0;
}