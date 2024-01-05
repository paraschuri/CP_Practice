class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto i: nums)mp[i]++;
        int ans=0;
        for(auto &[i,j]: mp){
            if(j==1)return -1;
            ans+=j/3;
            if(j%3!=0){
                ans++;
            }
        }
        return ans;
    }
};