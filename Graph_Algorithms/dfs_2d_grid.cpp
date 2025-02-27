#include<bits/stdc++.h>
using namespace std;
char grid[105][105];
bool vis[105][105];
vector<pair<int,int>>v={{-1,0},{1,0},{0,-1},{0,1}};
int n,m;

bool valid(int i,int j){
    if(i<0 or i>=n or j<0 or j>=m)
        return false;
    return true;
}

void dfs(int c,int d){
    cout<<c<<" "<<d<<endl;
    vis[c][d]=true;
    for(int i=0;i<4;i++){
        int a,b;
        a=c+v[i].first;
        b=d+v[i].second;
        if(valid(a,b) and !vis[a][b])
            dfs(a,b);
    }
}
int main(){
    int i,j;
    cin>>n>>m;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            cin>>grid[i][j];
        }
    }
    int si,sj;
    cin>>si>>sj;

    dfs(si,sj);
    return 0;
}