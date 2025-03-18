#include<bits/stdc++.h>
using namespace std;
const int N=1005;
vector<int>v(N);
int dp[N][N];

int subset_sum(int i,int sum){
    if(i<0){
        if(sum==0)
            return 1;
        return 0;
    }
    if(dp[i][sum]!=-1)
        return dp[i][sum];
    if(v[i]<=sum){
        int option1=subset_sum(i-1,sum-v[i]);
        int option2=subset_sum(i-1,sum);
        return dp[i][sum]=(option1 + option2);
    }
    else{
        int option2=subset_sum(i-1,sum);
        return dp[i][sum]=option2;
    }
}

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++)cin>>v[i];
    int sum;
    cin>>sum;
    for(int i=0;i<=n;i++)
        for(int j=0;j<=sum;j++)dp[i][j]=-1;
    int res=subset_sum(n-1,sum);
    cout<<res<<endl;
    return 0;  
}

/*
4
1 2 4 6
7
*/