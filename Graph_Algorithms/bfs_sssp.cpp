#include<bits/stdc++.h>
using namespace std;

const int N=1e5;
vector<int>graph[N];
bool vis[N];
int level[N];

void bfs(int source){
    queue<int>q;
    q.push(source);
    vis[source]=true;
    level[source]=0;//

    while(!q.empty()){
        int p=q.front();
        q.pop();

        for(int i=0;i<graph[p].size();i++){
            if(!vis[graph[p][i]]){
                q.push(graph[p][i]);
                level[graph[p][i]]=level[p]+1;//
                vis[graph[p][i]]=true;
            }
        }
    }
}

int main(){
    int v,e;
    cin>>v>>e;
    for(int i=0;i<e;i++){
        int x,y;
        cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    memset(level,-1,sizeof(level));
    int source,des;
    cin>>source>>des;
    bfs(source);

    cout<<level[des]<<endl;
    return 0;
}