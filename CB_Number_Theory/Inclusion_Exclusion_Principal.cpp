/*Utkarsh Sahay*/
#include <bits/stdc++.h>
using namespace std;
 
 
int main(){

    int a[] = {2,3,5};
    int n = sizeof(a) / sizeof(int);

    int ans = 0;
    int no = 999;

    for(int i = 1;i < (1 << n); i++){
        int mask = i;
        int bits = __builtin_popcount(mask);
        int temp = 1;
        int pos = 0;
        
        while(mask > 0){
            int lastBit = (mask & 1);
            if(lastBit){
                temp *= a[pos];
            }
            mask >>= 1;
            pos++;
        }
        if(bits & 1){
            ans += (no / temp);
        }
        else{
            ans -= (no / temp);
        }
    }

    cout<<ans<<endl;
 
    return 0;
}