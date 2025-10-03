/*Utkarsh Sahay*/
#include <bits/stdc++.h>
using namespace std;

int mod = 1e9+7;
vector<int> dp(1000001,-1);
int solve_dp(int num) {
    if (num == 0) return 1;
    if (num < 0) return 0;
    if(dp[num] != -1) return dp[num];

    int ways = 0;
    for (int i = 1; i <= 6; i++) {
       ways = (ways + solve_dp(num - i)) % mod;
    }
    return dp[num] = ways % mod;
}


void solve(){
    int ans = 0;
    int n;
    cin >> n;
    ans = solve_dp(n);
    cout<<ans<<endl;

}
 
int main(){

    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
 
    return 0;
}