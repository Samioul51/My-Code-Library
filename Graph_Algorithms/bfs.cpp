#include<bits/stdc++.h>
using namespace std;

const int N=1e5;
vector<int> g[N];
bool vis[N]={false};

void bfs(int source){
    queue<int>q;
    q.push(source);
    vis[source]=true;
    
    while(!q.empty()){
        //ber kore niye ashbo
        int v=q.front();
        q.pop();
        
        //oi node niye kaj
        cout<<v<<" ";

        //node tar children push korbo queue te
        for(int i=0;i<g[v].size();i++){
            if(!vis[g[v][i]]){
                q.push(g[v][i]);
                vis[g[v][i]]=true;
            }
        }
    }
    cout<<endl;
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
    int source;
    cin>>source;
    bfs(source);
    return 0;
}