#include<bits/stdc++.h>
using namespace std;
char grid[105][105];
bool vis[105][105];
int level[105][105];
pair<int,int> parent[105][105];
vector<pair<int,int>>v={{-1,0},{1,0},{0,-1},{0,1}};
int n,m;

bool valid(int i,int j){
    if(i<0 or i>=n or j<0 or j>=m)
        return false;
    return true;
}

void bfs(int a,int b){
    queue<pair<int,int>>q;
    q.push({a,b});
    vis[a][b]=true;
    level[a][b]=0;
    parent[a][b]={-1,-1};
    while(!q.empty()){
        pair<int,int> par=q.front();
        q.pop();

        int c=par.first;
        int d=par.second;
        cout<<c<<" "<<d<<endl;
        for(int i=0;i<4;i++){
            int e= c+v[i].first;
            int f= d+v[i].second;
            if(valid(e,f) and !vis[e][f]){
                q.push({e,f});
                vis[e][f]=true;
                level[e][f]=level[c][d]+1;
                parent[e][f]={c,d};
            }
        }
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
    int si,sj,di,dj;
    cin>>si>>sj>>di>>dj;
    memset(level,-1,sizeof(level));
    memset(parent,-1,sizeof(parent));
    
    bfs(si,sj);
    // while(1){
    //     pair<int,int> par=parent[x][y];
    //     x=par.first;
    //     y=par.second;
    // }
    cout<<level[di][dj]<<endl;
    return 0;
}