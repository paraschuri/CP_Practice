class Solution {
public:
    int minMoves(vector<int>& nums) {
        sort(begin(nums),end(nums));
        int ans=0,n=nums.size();
        for(int i=0;i<n-1;i++){
            ans+=(nums[i+1]-nums[i])*(n-i-1);
        }
        return ans;
    }
};