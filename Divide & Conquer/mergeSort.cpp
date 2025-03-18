#include<bits/stdc++.h>
using namespace std;

void merge(int c[],int l,int mid,int r){
    int n=mid-l+1,m=r-mid;
    int a[n],b[m];
    int k=l;
    for(int i=0;i<n;i++,k++){
        a[i]=c[k];
    }
    k=mid+1;
    for(int i=0;i<m;i++,k++){
        b[i]=c[k];
    }
    int i=0,j=0,curr=l;
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
}

void mergeSort(int a[],int l,int r){

    if(l<r){
        int mid=(l+r)/2;
        mergeSort(a,l,mid);
        mergeSort(a,mid+1,r);
        merge(a,l,mid,r);
    }
}


int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    
    mergeSort(a,0,n-1);
    
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return 0;
}