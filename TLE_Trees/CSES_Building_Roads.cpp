/*Utkarsh Sahay*/
#include <bits/stdc++.h>
using namespace std;
void dfs(int node, int par,vector<int> adj[], vector<bool> &vis){
    vis[node] = true;
    for(auto child : adj[node]){
        if(child != par && !vis[child]){
            dfs(child,node,adj,vis);
        }
    }
}
void solve(){
    int n,m;
    cin >> n >> m;
    vector<int> adj[n+1];

    for(int i = 0;i < m ; i++){
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int comp = 0;
    vector<int> nodes;
    vector<bool> vis(n+1,false);

    for(int i = 1; i <= n ; i++){
        if(!vis[i]){
            nodes.push_back(i);
            dfs(i,0,adj,vis);
            comp++;
        }
    }

    cout<<comp - 1<<endl;
    if(comp != 1)
        for(int i = 0;i < nodes.size()-1; i++) cout<<nodes[i]<<" "<<nodes[i+1]<<endl;
}
 
int main(){

    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
 
    return 0;
}