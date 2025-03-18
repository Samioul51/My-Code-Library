#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    int a[n],b[m];
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<m;i++)cin>>b[i];
    int c[n+m];
    int i=0,j=0,curr=0;
    while(i<n or j<m){
        if(i==n and j<m){
            c[curr]=b[j];
            curr++;
            j++;
            continue;
        }
        if(i<n and j==m){
            c[curr]=a[i];
            curr++;
            i++;
            continue;
        }
        if(a[i]<=b[j]){
            c[curr]=a[i];
            i++;
            curr++;
        }
        else{
            c[curr]=b[j];
            j++;
            curr++;
        }
    }
    for(i=0;i<n+m;i++)cout<<c[i]<<" ";
    cout<<endl;
    return 0;
}