#include<bits/stdc++.h>
using namespace std;



int main(){
    int v,e;
    cin>>v>>e;
    vector<pair<int,int>> edgelist;
    
    int i;
    for(i=0;i<e;i++){
        int u,v;
        cin>>u>>v;
        edgelist.push_back({u,v});
    }

    for(pair<int,int> x:edgelist){
        cout<< x.first <<" "<< x.second <<endl;
    }
    return 0;
}