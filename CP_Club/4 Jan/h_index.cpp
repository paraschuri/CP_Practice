class Solution {
public:
    int hIndex(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int n=arr.size(),ans=n;
        for(int i=0;i<n;i++){
            if(arr[i]>=ans){
                break;
            }
            ans--;
        }
        return ans;
    }
};