class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            if(i && nums[i]==nums[i-1])continue;
            for(int j=i+1;j<n;j++){
                if(j!=i+1 && nums[j]==nums[j-1])continue;
                int k=j+1,l=n-1;
                while(k<n && l>k){
                    long long temp = 1ll*nums[i]+1ll*nums[j]+1ll*nums[k]+1ll*nums[l];
                    if((temp<target) || (k!=j+1 && nums[k]==nums[k-1])){
                        k++;
                    }
                    else if(temp==target){
                        ans.push_back({nums[i],nums[j],nums[k],nums[l]});
                        k++;
                    }
                    else{
                        l--;
                    }
                }
            }
        }
        return ans;
    }
};