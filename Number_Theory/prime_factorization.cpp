
void PrimeFact(int n){
    for(int i=2;i*i<=N;i++){
        if(n%i==0){
            int count=0;
            while(n%i){
                count++;
                n/=i;
            }
            cout<<i<<"^"<<count<<endl;
        }
    }
    if(n>1)
        cout<<n<<"^1"<< endl;

}

//O(sqrt(n))