class Solution {
public:
    vector<int> cnt;
    void merge(int l,int m,int h,vector<pair<int,int>>& arr){
        vector<pair<int,int>> temp;
        int i=l,j=m+1;
        int k=0;
        while(i<=m && j<=h){
            if(arr[i].first>arr[j].first){
                k++;
                temp.push_back(arr[j]);
                j++;
            }
            else{
                cnt[arr[i].second]+=k;
                temp.push_back(arr[i]);
                i++;
            }
        }
        while(i<=m){
            temp.push_back(arr[i]);
            cnt[arr[i].second]+=k;
            i++;
        }
        while(j<=h){
            temp.push_back(arr[j]);
            j++;
        }
        for(int i=0;i<temp.size();i++){
            arr[i+l]=temp[i];
        }
    }
    void mergeSort(int l,int h,vector<pair<int,int>>& arr){
        if(l>=h)return;
        int m = (l+h)/2;
        mergeSort(l,m,arr);
        mergeSort(m+1,h,arr);
        merge(l,m,h,arr);
    }
    vector<int> countSmaller(vector<int>& nums) {
        vector<pair<int,int>> arr;
        int n=nums.size();
        for(int i=0;i<n;i++){
            arr.push_back({nums[i],i});
        }
        cnt.resize(n,0);
        mergeSort(0,n-1,arr);
        return cnt;
    }
};