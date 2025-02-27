#include<bits/stdc++.h>
using namespace std;

const int N=105;
const int INF=INT_MAX;
int adj_mat[N][N];

void floyd_warshall(int n){
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(adj_mat[i][k]!=INF and adj_mat[k][j]!=INF and adj_mat[i][k]+adj_mat[k][j]<adj_mat[i][j])
                    adj_mat[i][j]=adj_mat[i][k]+adj_mat[k][j];
            }
        }
    }
    bool cycle=false;
    for(int i=0;i<n;i++){
        if(adj_mat[i][i]<0){
            cycle=true;
            break;
        }
    }
    if(cycle)
        cout<<"Negative weighted cycle detected"<<endl;
    else{
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(adj_mat[i][j]==INF)
                    cout<<"INF"<<" ";
                else
                    cout<<adj_mat[i][j]<<" ";
            }
            cout<<endl;
        }
    }
}

int main(){
    int i,j,n,e;
    cin>>n>>e;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(i==j)
            {
                adj_mat[i][j]=0;
                continue;
            }
            adj_mat[i][j]=INF;
        }
    }

    while(e--){
        int a,b,c;
        cin>>a>>b>>c;
        adj_mat[a][b]=c;
        //adj_mat[b][a]=c; //for undirected
    }

    floyd_warshall(n);

    return 0;
}

/*

4 5
0 1 3
0 2 6
1 2 2
1 3 5
2 3 4

*/