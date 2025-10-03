// Utkarsh Sahay
#include <bits/stdc++.h>
using namespace std;

void dfs(int node,vector<int> adj[], int par, vector<int> &subtree){
    subtree[node] = 1;
    for(auto child : adj[node]){
        if(child == par) continue;
        dfs(child,adj,node,subtree);
        subtree[node] += subtree[child]; 
    }

}
 
void solve(){
    int n;
    cin>>n;
    
    vector<int> adj[n+1];
    vector<int> nodes(n-1);
    for(int i = 0;i < n-1; i++) cin>>nodes[i];
    int u = 2;
    for(int i = 0;i < n-1; i++){
        adj[u].push_back(nodes[i]);
        adj[nodes[i]].push_back(u);
        u++;
    }

    vector<int> subtree(n+1,0);

    int par = 0;
    dfs(1,adj,par,subtree);
    for(int i = 1;i < subtree.size(); i++){
        cout<<subtree[i] - 1<<" ";
    }
}
 
int main(){
    solve();
    // int t;
    // cin >> t;
    // while(t--){
    //     solve();
    // }
 
    return 0;
}