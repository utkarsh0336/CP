/*Utkarsh Sahay*/
#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;
void solve(int N, int X, vector<int>& coins)
{
    // dp[] array such that dp[i] stores the number of
    // ordered ways to construct sum i
    vector<int> dp(X + 1, 0);

    // Initialize dp[0] = 1 as there is only one way to
    // construct sum 0 that is to not choose any coin
    dp[0] = 1;

    // Iterate over all coins from 0 to N - 1
    for (int i = 0; i < N; i++) {
        // Iterate over all sums j from coins[i] to X
        for (int j = coins[i]; j <= X; j++) {
            // Add the number of ways to construct sum (j -
            // coins[i]) to dp[j]
            dp[j] = (dp[j] + dp[j - coins[i]]) % mod;
        }
    }

    // Return the number of ordered ways to construct sum X
    cout << dp[X] <<endl;
}

void Solve(){
    int n,x;
    cin >> n >> x;
    vector<int> a(n);
    for(int i = 0;i < n; i++){
        cin >> a[i];
    }

    solve(n,x,a);
}
 
int main(){

    int t = 1;
    // cin >> t;
    while(t--){
        Solve();
    }
 
    return 0;
}