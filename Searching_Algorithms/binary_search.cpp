int binary_search(vector<int> v, int key){
    int low=0;
    int high= v.size()-1;
    int mid;
    while(low<=high){
        mid=low+(high-low)/2;
        if(v[mid]==key)
            return mid;
        else if(v[mid]<key)
            low=mid+1;
        else
            high=mid-1;
    }

    return -1;
}
