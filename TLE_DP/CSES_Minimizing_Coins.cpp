/*Utkarsh Sahay*/
#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

// dp[sum] = number of ways to make sum
void solve(int x,vector<int> &a,vector<int> &dp){
    dp[0] = 0;

    for(int i = 0;i <= x; i++){
        for(int j = 0; j < a.size(); j++){
            if(i - a[j] >= 0 && dp[i-a[j]] != -1){
                if(dp[i] == -1){
                    dp[i] = 1 + dp[i-a[j]];
                }
                else{
                    dp[i] = min(dp[i] , 1 + dp[i-a[j]]);
                }
            }
        }
    }

    cout<<dp[x]<<endl;
}

void solve1() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

   vector<int> dp(x + 1, -1);
   solve(x,a,dp);

}

int main() {
    int t = 1;
    while (t--) {
        solve1();
    }
    return 0;
}
