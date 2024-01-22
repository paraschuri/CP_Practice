class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        map<int,int> mp;
        for(int i=0;i<k;i++){
            mp[nums[i]]++;
        }   
        vector<int> ans;
        ans.push_back(mp.rbegin()->first);
        for(int i=0;i<n-k;i++){
            mp[nums[i]]--;
            if(!mp[nums[i]])mp.erase(nums[i]);
            if(i<n-k){
                mp[nums[i+k]]++;
            }
            ans.push_back(mp.rbegin()->first);
        }
        return ans;
    }
};