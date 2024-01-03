class Solution {
public:
    static bool cmp(const int &a,const int& b){
        string x=to_string(a),y=to_string(b);
        string m=x+y,n=y+x;
        return m>n;
    }
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end(),cmp);
        string ans="";
        if(count(nums.begin(),nums.end(),0)==nums.size())return "0";
        for(auto i: nums){
            ans+=to_string(i);
        }
        return ans;
    }
};