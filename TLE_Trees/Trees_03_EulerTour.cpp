/*Utkarsh Sahay*/
#include <bits/stdc++.h>
using namespace std;
// Euler Tour :- The path traced by the DFS
vector<int> tree_flatten;
vector<int> tree_flatten2;
map<int,int> mp;  // node in tree_flatten -> first index of that node in tree_flatten
map<int,pair<int,int>> mp2;
int idx = 0;
// This is type-1
void EulerTour(int node,int par,vector<int> adj[],vector<int> &level,int l = 0){
    // cout<<node<<" ";
    if(mp.find(node) == mp.end()){
        mp[node] = idx;
    }
    tree_flatten.push_back(node);
    idx++;
    level[node] = l;
    for(auto child : adj[node]){
        if(child == par) continue;
        // cout<<child<<" ";
        EulerTour(child,node,adj,level,l+1);
        // cout<<node<<" ";
        tree_flatten.push_back(node);
        idx++;
    }
}


// Type-1 of Euler Tour
// After Euler Tour Flattening make another vector<int> level and store the level according to the nodes present in the tree_flatten
// Euler Tour nikalne ke baad jin do nodes (a , b) ka LCA mangta hai...euler tour mein un dono nodes ke bich ka sabhi nodes ka level dekho jiska level sabse kam hoga wo LCA(a,b) hoga.









void EulerTour2(int node,int par,vector<int> adj[]){
    // cout<<node<<" ";

    mp2[node].first = idx;    
    tree_flatten2.push_back(node);
    idx++;
    for(auto child : adj[node]){
        if(child != par){
            EulerTour2(child,node,adj);
        }
    }
    // cout<<node<<" ";
     mp2[node].second = idx;    
    tree_flatten2.push_back(node);
    idx++;
}


void solve(){
    int n;
    cin>>n;
    vector<int> adj[n+1];
    vector<int> level(n+1,0);
    vector<int> level_of_flatten_tree;

    for(int i = 0;i < n-1; i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // EulerTour(1,0,adj,level,0);

    // for(auto it : tree_flatten){
    //     level_of_flatten_tree.push_back(level[it]);
    // }

    // for(int l : level) cout<<l<<" ";
    // for(auto it : level_of_flatten_tree) cout<<it<<" ";



    // Euler Tour 2 prints the nodes when entering and exiting while in Euler Tour 1 , it prints the node when encountered during dfs traversal
    EulerTour2(1,0,adj);
    for(auto it : tree_flatten2) cout<<it<<" ";



}
 
int main(){

    int t;
    cin >> t;
    while(t--){
        solve();
    }
 
    return 0;
}