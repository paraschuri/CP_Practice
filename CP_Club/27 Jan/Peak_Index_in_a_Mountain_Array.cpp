class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n=arr.size();
        int low=1,high=n-2;
        while(low<=high){
            int i = low + (high-low)/2;
            if(arr[i]>arr[i-1] && arr[i]>arr[i+1]){
                return i;
            }
            else if(arr[i]>arr[i-1] && arr[i]<arr[i+1]){
                low=i+1;
            }
            else{
                high=i-1;
            }
        }
        return 0;

    }
};