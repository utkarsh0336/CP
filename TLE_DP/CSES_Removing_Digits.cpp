/*Utkarsh Sahay*/
#include <bits/stdc++.h>
using namespace std;

int solve(int n){
   int largest = 0;
   int smallest = 9;

   while(n){
    int dig = n % 10;
    largest = max(largest,dig);
    n /= 10;
   }
   return largest;
}

void Solve(){
    int n;
    cin >> n;
    int ans = 0;
    while(n){
        int lar = solve(n);
        n -= lar;
        ans++;
    }
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