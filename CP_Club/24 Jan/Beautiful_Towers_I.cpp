class Solution {
public:
    long long maximumSumOfHeights(vector<int>& arr) {
        long long ans = 0, n = arr.size();
        for(int i=0;i<n;i++){
            long long curr=arr[i];
            int j = i-1,prev = arr[i];
            while(j>=0){
                prev = min(arr[j],prev);
                curr += prev;
                j--;
            }
            j = i+1,prev = arr[i];
            while(j<n){
                prev = min(arr[j],prev);
                curr += prev;
                j++;
            }
            ans = max(ans,curr);
        }   
        return ans;
    }
};