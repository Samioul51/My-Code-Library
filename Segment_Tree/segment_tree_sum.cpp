const int N=1e5+5;
ll a[N],t[4*N];

void build(int n,int b,int e){
    if(b==e){
        t[n]=a[b];
        return;
    }
    int mid=(b+e)/2,l=2*n,r=2*n+1;
    build(l,b,mid);
    build(r,mid+1,e);
    t[n]=t[l]+t[r];
}

void update(int n,int b,int e,int x,int v){
    if(x<b or x>e)
        return;
    if(b==e){
        t[n]=v;
        return;
    }
    int mid=(b+e)/2,l=2*n,r=2*n+1;
    update(l,b,mid,x,v);
    update(r,mid+1,e,x,v);
    t[n]=t[l]+t[r];
}

ll query(int n,int b,int e,int x,int y){
    if(e<x or y<b)
        return 0;
    if(b>=x and e<=y)
        return t[n];
    int mid=(b+e)/2,l=2*n,r=2*n+1;
    return query(l,b,mid,x,y)+query(r,mid+1,e,x,y);
}

void SIR(){
    int n,m;
    cin>>n>>m;
    cf(i,1,n)cin>>a[i];
    build(1,1,n);
    while(m--){
        int t;
        cin>>t;
        if(t==1){
            int idx,v;
            cin>>idx>>v;
            idx++;
            update(1,1,n,idx,v);
        }
        else{
            int l,r;
            cin>>l>>r;
            l++;
            long long res=query(1,1,n,l,r);
            cout<<res<<"\n";
        }
    }
}
