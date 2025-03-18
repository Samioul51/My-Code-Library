#include<bits/stdc++.h>
using namespace std;
const int N=1005;
vector<int>v(N);
int dp[N][N];

bool subset_sum(int i,int sum){
    if(i<0){
        if(sum==0)
            return true;
        return false;
    }
    if(dp[i][sum]!=-1)
        return dp[i][sum];
    if(v[i]<=sum){
        bool option1=subset_sum(i-1,sum-v[i]);
        bool option2=subset_sum(i-1,sum);
        return dp[i][sum]=(option1 or option2);
    }
    else{
        bool option2=subset_sum(i-1,sum);
        return dp[i][sum]=option2;
    }
}

int main(){
    int n,sum=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>v[i];
        sum+=v[i];
    }
    if(sum%2)
        cout<<"NO"<<endl;
    else{
    for(int i=0;i<=n;i++)
        for(int j=0;j<=sum;j++)dp[i][j]=-1;
    bool res=subset_sum(n-1,sum/2);
    if(res)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
    }
    return 0;  
}

/*
4
1 2 4 6
7
*/