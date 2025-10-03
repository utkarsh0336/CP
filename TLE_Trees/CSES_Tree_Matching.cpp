/*Utkarsh Sahay*/
#include <bits/stdc++.h>
using namespace std;

void dfs(long long node,long long par,vector<long long> adj[],vector<vector<long long>> &dp){
    for(auto it : adj[node]){
        if(it == par) continue;
        dfs(it,node,adj,dp);
        dp[node][0] += max(dp[it][0],dp[it][1]);
    }

    for(auto it : adj[node]){
        if(it == par) continue;
        dp[node][1] = max(dp[node][1] , 1 + dp[node][0] + dp[it][0] - max(dp[it][0],dp[it][1]));
    }
}
void solve(){
    long long n;
    cin>>n;
    
    vector<long long> adj[n+1];
    vector<vector<long long>> dp(n+1,vector<long long>(2,0));

    for(long long i = 0;i < n-1; i++){
        long long u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1,0,adj,dp);
    cout<<max(dp[1][0],dp[1][1])<<endl;

}
 
int main(){

 int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
 
    return 0;
}