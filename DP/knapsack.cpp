#include<bits/stdc++.h>
using namespace std;

int val[1005],weight[1005];
int dp[1005][1005];

//complexity O(n*w)

int knapsack(int i,int max_weight){
    if(i<0 or max_weight<=0)
        return 0;
    
    if(dp[i][max_weight]!=-1)
        return dp[i][max_weight];

    if(weight[i]<=max_weight){
        /*
        2 options
        1. will put in the bag
        2. wont put int the bag
        */
        int option1=knapsack(i-1,max_weight-weight[i])+val[i];
        int option2=knapsack(i-1,max_weight);
        dp[i][max_weight]=max(option1,option2);
        return dp[i][max_weight];
    }
    else{
        /*
        1 option
        cant put in the bag
        */
        dp[i][max_weight]=knapsack(i-1,max_weight);
        return dp[i][max_weight];
    }
}


int main(){
    
    int n,max_weight;
    cin>>n;
    
    for(int i=0;i<n;i++){
        cin>>val[i];
    }
    
    for(int i=0;i<n;i++){
        cin>>weight[i];
    }
    
    cin>>max_weight;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<=max_weight;j++){
            dp[i][j]=-1;
        }
    }
    
    cout<<knapsack(n-1,max_weight)<<endl;;
    
    return 0;
}

/*
4
10 4 7 5
4 3 2 5
8
Ans:17

*/