/*Utkarsh Sahay*/
#include <bits/stdc++.h>
using namespace std;

vector<int> tree_flatten;
int idx = 0;
map<int,pair<int,int>> mp;

void EulerTour2(int node,int par,vector<int> adj[]){
    tree_flatten.push_back(node);
    mp[node].first = idx;
    idx++;
    for(auto it : adj[node]){
        if(it != par){
            EulerTour2(it,node,adj);
        }
    }
    tree_flatten.push_back(node);
    mp[node].second = idx;
    idx++;
}

// void changeNodeVal(int node,int val,vector<int> &nodes){
//     nodes[node] = val;
// }

void solve(){
    int n,q;
    cin>>n>>q;
    vector<int> adj[n+1],nodes(n+1);
    for(int i = 0;i < n; i++) cin>>nodes[i];
    for(int i = 0;i < n-1; i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    EulerTour2(1,0,adj);

    for(auto it : mp){
        nodes[it.second.second] = -(it.first);
    }

    for(int i = 0;i < q; i++){
        int t;
        cin>>t;
        int node = -1 , val = -1, sum = 0;
        if(t == 1){
           cin >> node;
           cin >> val;
           nodes[node-1] = val;
        }
        else{
            cin >> node;
            int l = mp[node].first;
            int r = mp[node].second;
            for(int j = 0; j < mp[node].second; j++) sum += nodes[tree_flatten[j]-1];
            cout<<sum<<endl;
        }
    }
}
 
int main(){

    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
 
    return 0;
}