/*Utkarsh Sahay*/
#include <bits/stdc++.h>
using namespace std;


void Solve(){
    int n;
    cin >> n;

    vector<vector<char>> grid(n,vector<char>(n));

    for(int i = 0;i < n; i++){
        for(int j = 0;j < n; j++){
            cin >> grid[i][j];
        }
    }

    

}
 
int main(){

    int t;
    cin >> t;
    while(t--){
        Solve();
    }
 
    return 0;
}