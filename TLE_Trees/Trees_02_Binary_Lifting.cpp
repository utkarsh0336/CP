/*Utkarsh Sahay*/
#include <bits/stdc++.h>
using namespace std;
// Every number can be represented as the sum of powers of 2
void dfs(int node,vector<int> adj[],int par,vector<vector<int>> &dp){
    dp[node][0] = par;   // dp[node][k] = 2^kth parent of node. 
    for(int i = 1; i <= 16; i++){
        dp[node][i] = dp[dp[node][i-1]][i-1];
    }
    for(auto it : adj[node]){
        if(it == par) continue;
        dfs(it,adj,node,dp);
    }
}

int getKthParent(int node,int k,vector<vector<int>> &dp){
    // int cnt = 0;
        // while(k--){
        //     if(k & 1){
        //         node = dp[node][cnt];
        //     }
        //     cnt++;
        //     k = k >> 1;
        // }
        // cout<<node<<" ";

     for(int i = 16; i >= 0 ; i--){
            if((k >> i) & 1){
                node = dp[node][i];
            }
        }
        return node;
}

void dfs_LCA_Binary_Lifting(int node,vector<int> adj[],int par,vector<vector<int>> &dp,vector<int> &level,int l = 0){
    dp[node][0] = par; 
    for(int i = 1; i <= 16; i++){
        dp[node][i] = dp[dp[node][i-1]][i-1];
    }
    level[node] = l;
    for(auto it : adj[node]){
        if(it == par) continue;
        dfs_LCA_Binary_Lifting(it,adj,node,dp,level,l+1);
    }
}

void solve(){
    int n;
    cin>>n;
    vector<int> adj[n+1];
    vector<int> level(n+1,-1);
    for(int i = 0;i < n-1; i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<vector<int>> dp(n+1,vector<int>(17,0));
    int q;
    cin >> q;
    while(q--){
        // int node , k;
        // cin >> node >> k;
        // print the kth parent of a node.
        // dfs(1,adj,0,dp);
        
        dfs_LCA_Binary_Lifting(1,adj,0,dp,level,0);

        // Step 1 :- Bring them to the same level using binary lifting
        // Step 2 :- Move a and b to every unequal node (from 16 to 0)
        
        int a , b;   // LCA(a,b)
        cin>>a>>b;

        if(level[a] > level[b]){
            swap(a,b);
        }

        // a is at lower level
        int k = level[b] - level[a];
        b = getKthParent(b,k,dp);
        if(a == b){
            cout<<a<<endl;
            continue;
        }
        // now both a and b are at same level now
        for(int i = 16; i >= 0; i--){
            if(dp[a][i] != dp[b][i]){
                a = dp[a][i];
                b = dp[b][i];
            }
        }

        cout << dp[a][0] << endl;

       
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