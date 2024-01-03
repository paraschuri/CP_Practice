class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums){ 
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            if(i && nums[i]==nums[i-1])continue;
            int j=i+1,k=n-1;
            while(j<n && k>j){
                if((nums[i]+nums[j]+nums[k]<0) || (j!=i+1 && nums[j]==nums[j-1])){
                    j++;
                }
                else if(nums[i]+nums[j]+nums[k]==0){
                    ans.push_back({nums[i],nums[j],nums[k]});
                    j++;
                }
                else{
                    k--;
                }
            }
        }
        return ans;
    }
};