/*Utkarsh Sahay*/
#include <bits/stdc++.h>
using namespace std;

map<int,pair<int,int>> mp;
// label -> {in_time , out_time}
int t = 0;

void dfs(int node, vector<int> adj[] , int par){
    // we are entering the node
    mp[node].first = t;
    t++;
    cout<<node<<" ";
    for(auto child : adj[node]){
        if(child == par){
            continue;
        }
        dfs(child,adj,node);
    }
    mp[node].second = t;
    t++;
    // we are leaving the node
}

void bfs(int node, vector<int> adj[]){
    queue<pair<int,int>> q;
    // {node , parent}
    q.push({node,0});
    while(!q.empty()){
        int n = q.size();
        for(int i = 0;i < n; i++){
            int u = q.front().first;
            int par = q.front().second;
            q.pop();
            cout<<u<<" ";

            for(auto child : adj[u]){
                if(child == par) continue;
                q.push({child,u});
            }
        }
    }
}

void height_using_bfs(int node,vector<int> adj[] , vector<int> &level){
    queue<pair<int,int>> q;
    q.push({node,0});
    int l = 0;
    while(!q.empty()){
        int n = q.size();
        for(int i = 0;i < n; i++){
            int u = q.front().first;
            int par = q.front().second;
            q.pop();

            for(auto child : adj[u]){
                if(child == par) continue;
                q.push({child,u});
                level[child] = l;
                l++;
            }
        }
    }
}

void height_using_dfs(int node,vector<int> adj[] ,int par, vector<int> &level, int l = 0){
    level[node] = l;

    for(auto child : adj[node]){
        if(child == par) continue;
        height_using_dfs(child,adj,node,level,l+1);
    }
}

void solve(){
    int n;  // number of vertices
    cin>>n;
    vector<int> adj[n+1];
    vector<int> level(n+1,0);
    int maxL = 0;

    for(int i = 0;i < n-1; i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // dfs(1,adj,0);
    // bfs(1,adj);


    // height_using_bfs(1,adj,level);
    height_using_dfs(1,adj,0,level,0);
    for(int i = 0;i < level.size(); i++){
        maxL = max(maxL , level[i]);
    }

    cout<<"Height : "<<maxL + 1;


    // cout<<endl;
    // for(auto it : mp){
    //     cout<<"Node : "<<it.first<< " -> "<<it.second.first<<" ," << it.second.second<<endl;
    // }
}
 
int main(){
    int t;
    cin >> t;

    while(t--){
        solve();
    }
 
    return 0;
}