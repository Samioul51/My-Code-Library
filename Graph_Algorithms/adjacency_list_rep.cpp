#include<bits/stdc++.h>
using namespace std;



int main(){
    int v,e;
    cin>>v>>e;
    vector<int> g[v];
    int i,j;
    for(i=0;i<e;i++){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);//for undirected
    }

    for(i=0;i<v;i++){
        cout<<i<<" -> ";
        for(int x:g[i]){
            cout<<x<<" ";
        }
        cout<<endl;
    }
    return 0;
}