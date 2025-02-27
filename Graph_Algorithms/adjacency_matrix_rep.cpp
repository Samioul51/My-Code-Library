#include<bits/stdc++.h>
using namespace std;



int main(){
    int vertices,edges;
    cin>>vertices>>edges;
    
    int g[vertices][vertices];
    int i,j;
    memset(g,0,sizeof(g));
    
    for(i=0;i<edges;i++){
        int u,v;
        cin>>u>>v;
        g[u][v]=1;
        g[v][u]=1;//for undirected not included in directed
    }

    for(i=0;i<vertices;i++){
        for(j=0;j<vertices;j++){
            if(i==j)
                g[i][j]=1;    //ekta node nij theke nijer node e jete pare
        }
        
    }

    for(i=0;i<vertices;i++){
        for(j=0;j<vertices;j++){
            cout<<g[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}