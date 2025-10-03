/*Utkarsh Sahay*/
#include <bits/stdc++.h>
using namespace std;

int solve(int i,vector<int> &prices,vector<int> &pages, int x,vector<vector<int>> &dp){
    if(i == prices.size()) return 0;
    if(x <= 0) return 0;
    if(dp[i][x] != -1) return dp[i][x];
 
    int take = 0;
    int skip = 0;
 
    if(x >= prices[i]){
        take = pages[i] + solve(i+1,prices,pages,x-prices[i],dp);
        skip += solve(i+1,prices,pages,x,dp);
    }
    else{
        skip += solve(i+1,prices,pages,x,dp);
    }
 
    return dp[i][x] = max(take,skip);
 
 
}
 
void Solve(){
    int n , x;
    cin >> n >> x;
 
    vector<vector<int>> dp(n+1,vector<int>(x+1,-1));
    vector<int> prices(n),pages(n);
 
    for(int i = 0;i < n; i++) cin >> prices[i];
    for(int i = 0;i < n; i++) cin >> pages[i];
 
    int ans = solve(0,prices,pages,x,dp);
    cout<<ans<<endl;
}
 
int main(){
 
    int t = 1;
    // cin >> t;
    while(t--){
        Solve();
    }
 
    return 0;
}