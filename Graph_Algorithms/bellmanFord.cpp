#include<bits/stdc++.h>
using namespace std;

class Edge{
    public:
        int a,b,c;
        Edge(int a, int b, int c){
            this->a=a;
            this->b=b;
            this->c=c;
        }
};

vector<Edge> edge_list;
int dis[1005];

void bellmanFord(int n, int source){
    dis[source]=0;
    for(int i=1;i<=n-1;i++){
    for(auto ed:edge_list){
        int a,b,c;
        a=ed.a;
        b=ed.b;
        c=ed.c;
        if(dis[a]!=INT_MAX and dis[a]+c<dis[b])
            dis[b]=dis[a]+c;
        }
    }
    
    bool cycle=false;

    for(auto ed:edge_list){
        int a,b,c;
        a=ed.a;
        b=ed.b;
        c=ed.c;
        if(dis[a]!=INT_MAX and dis[a]+c<dis[b]){
            cycle=true;
            break;
        }
    }
    if(cycle)
        cout<<"Negative weighted Cycle detected"<<endl;
    else{
        for(int i=0;i<n;i++){
            cout<<dis[i]<<endl;
        }
    }
}

int main(){
    int n,e;
    cin>>n>>e;
    
    while(e--){
        int a,b,c;
        cin>>a>>b>>c;
        edge_list.push_back(Edge(a,b,c));
        // edge_list.push_back(Edge(b,a,c)); for undirected
    }

    // for(auto ed:edge_list){
    //     cout<<ed.a<<" "<<ed.b<<" "<<ed.c<<endl;
    // }

    for(int i=0;i<n;i++){
        dis[i]=INT_MAX;
    }

    bellmanFord(n,0);

    
    return 0;
}

/*

4 4
0 2 5
0 3 12
2 1 2
1 3 3

*/