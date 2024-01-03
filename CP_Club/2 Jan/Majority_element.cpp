class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int mx=0,cnt=0;
        for(auto i: nums){
            if(cnt==0){
                mx=i;
                cnt++;
            }
            else{
                if(i==mx){
                    cnt++;
                }
                else{
                    cnt--;
                }
            }
        }
        return mx;
    }
};