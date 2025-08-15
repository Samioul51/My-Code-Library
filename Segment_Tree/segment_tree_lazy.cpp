const int N=1e5+5;
ll a[N],t[N*4],lazy[N*4];

void push(int n,int b,int e){
    if(lazy[n]==0)
        return;
    t[n]+=1LL*(e-b+1)*lazy[n];
    if(b!=e){
        int l=2*n,r=2*n+1;
        lazy[l]+=lazy[n];
        lazy[r]+=lazy[n];
    }
    lazy[n]=0;
}

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

void update(int n,int b,int e,int x,int y,int v){
    push(n,b,e);
    if(y<b or x>e)
        return;
    if(b>=x and e<=y){
        lazy[n]=v;
        push(n,b,e);
        return;
    }
    int mid=(b+e)/2,l=2*n,r=2*n+1;
    update(l,b,mid,x,y,v);
    update(r,mid+1,e,x,y,v);
    t[n]=t[l]+t[r];
}

ll query(int n,int b,int e,int x,int y){
    push(n,b,e);
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
    build(1,1,n);
    while(m--){
        int t;
        cin>>t;
        if(t==1){
            int l,r,v;
            cin>>l>>r>>v;
            l++;
            update(1,1,n,l,r,v);
        }
        else{
            int l;
            cin>>l;
            l++;
            long long res=query(1,1,n,l,l);
            cout<<res<<"\n";
        }
    }
}
