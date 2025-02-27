#include<bits/stdc++.h>
using namespace std;

const int INF=INT_MAX;
vector<pair<int,int>> g[105];
int dis[105];
int parent[105];


void dijkstra(int src){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,src}); // {dis, node}
    dis[src]=0;
    parent[src]=-1;

    while(!pq.empty()){
        pair<int,int> par=pq.top();
        pq.pop();
        int par_node=par.second;
        int par_dis=par.first;
        
        for(auto child:g[par_node]){
            int child_node=child.first;
            int child_dis=child.second;
            if(par_dis+child_dis < dis[child_node]){
                dis[child_node]=par_dis+child_dis;
                parent[child_node]=par_node;
                pq.push({dis[child_node],child_node});
            }
        }
    }
}

int main(){
    int n,e;
    cin>>n>>e;
    for(int i=0;i<e;i++){
        int u,v,w;
        cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    fill(dis,dis+105,INF);
    int src;
    cin>>src;
    dijkstra(src);
    cout<<"Souce :"<<src<<endl;
    for(int i=0;i<n;i++){
        cout<< i<<" "<<dis[i]<<endl;
    }
    return 0;
}