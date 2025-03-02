#include<bits/stdc++.h>
using namespace std;

long long int dp[1001];


//top down
long long int fibo(int n){
    if(n<2)
        return n;
    if(dp[n]!=-1)
        return dp[n];
    return dp[n]=fibo(n-1)+fibo(n-2);
}


//bottom up

// long long int fibo(int n){
//     dp[0]=0;
//     dp[1]=1;
//     for(int i=2;i<=n;i++){
//         dp[i]=dp[i-1]+dp[i-2];
//     }
//     return dp[n];
// }


int main(){
    memset(dp,-1,sizeof(dp));
    cout<<fibo(50);
    return 0;
}
