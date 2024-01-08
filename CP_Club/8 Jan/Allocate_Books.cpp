bool ok(int mid,vector<int>& arr,int m){
    long long cnt=1,sum=0;
    for(auto i: arr){
        if(sum+i>mid){
            sum=i;
            cnt++;
        }
        else{
            sum+=i;
        }
    }
    return cnt<=m;
}

int findPages(vector<int>& arr, int n, int m) {
    if(m>n)return -1;
    long long low = *max_element(arr.begin(),arr.end()), high = accumulate(arr.begin(),arr.end(),0ll);
    int ans=-1;
    while(low<=high){
        long long mid = low+(high-low)/2;
        if(ok(mid,arr,m)){
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return low;
}