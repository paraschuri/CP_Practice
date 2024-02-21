class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int cmp = INT_MIN,n = nums.size();
        stack<int> st;
        for( int i = n-1; i >= 0; i -- ){
            if( nums[i] < cmp ) return true;
            else while( !st.empty() && nums[i] > st.top() ){ 
              cmp = st.top(); st.pop(); 
            }
            st.push(nums[i]);
        }
        return false;
    }
};