/*Utkarsh Sahay*/
#include <bits/stdc++.h>
using namespace std;

void dfs(int node,int par,vector<int> adj[],vector<vector<int>> &dp,vector<int> &level,int l = 0){
    dp[node][0] = par;
    for(int i = 1;i <= 19; i++){
        dp[node][i] = dp[dp[node][i-1]][i-1];
    }
    level[node] = l;

    for(auto it : adj[node]){
        if(it == par) continue;
        dfs(it,node,adj,dp,level,l+1);
    }
}

int getKthParent(int node, int k, vector<vector<int>> &dp) {
    for (int i = 19; i >= 0; i--) {
        if ((k >> i) & 1) {
            if (node == -1) break;
            node = dp[node][i];
        }
    }
    return node;
}

void solve(){
    int n,q;
    cin>>n>>q;
    
    vector<int> adj[n+1];
    vector<int> level(n+1,0);
    vector<vector<int>> dp(n+1,vector<int>(20,0));


    for(int v = 2; v <= n ; v++){
        int u;
        cin>>u;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1,0,adj,dp,level,0);

    for(int i = 0;i < q; i++){
        int a,b;
        cin >> a >> b;

        if(level[a] > level[b]){
            swap(a,b);
        }

        int k = level[b] - level[a];
        b = getKthParent(b,k,dp);

        if(a == b){
            cout<<a<<endl;
            continue;
        }

        for(int i = 19; i >= 0; i--){
            if(dp[a][i] != dp[b][i]){
                a = dp[a][i];
                b = dp[b][i];
            }
        }

        cout<<dp[a][0]<<endl;
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