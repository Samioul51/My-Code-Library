#include<bits/stdc++.h>
using namespace std;

const int N=1e5+5;
vector<int>g[N];
vector<bool> vis(N);

void dfs(int source){

    cout<<source<<" ";
    vis[source]=true;
    
    for(int i=0;i<g[source].size();i++){
        int v=g[source][i];
        if(!vis[v])
            dfs(v);
    }
}

int main(){
    int n,e;
    cin>>n>>e;
    for(int i=0;i<e;i++){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    fill(vis.begin(),vis.end(),false);
    dfs(0);
    return 0;
}

/*
7 7
0 2
2 4
0 1
0 3
1 3
1 5
3 6
*/