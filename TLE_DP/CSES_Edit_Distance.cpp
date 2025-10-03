/*Utkarsh Sahay*/
#include <bits/stdc++.h>
using namespace std;

int dp[5001][5001];
int solve(int i,int j,string &s,string  &t){
    if(j == t.size()) return s.size() - i;
    if(i == s.size()) return t.size() - j;
    if(dp[i][j] != -1) return dp[i][j];

    if(s[i] == t[j]) return solve(i+1,j+1,s,t);
    int insert = 1 + solve(i,j+1,s,t);
    int del = 1 + solve(i+1,j,s,t);
    int replace = 1 + solve(i+1,j+1,s,t);

    return dp[i][j] = min({insert,del,replace});
}

void Solve(){
    string s,t;
    cin >> s;
    cin >> t;

    memset(dp,-1,sizeof(dp));
    int ans = solve(0,0,s,t);
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