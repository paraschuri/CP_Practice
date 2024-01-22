class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size(),mod=1e9+7;
        vector<int> pref(n),suff(n);
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[i]<arr[st.top()])st.pop();
            if(!st.empty())pref[i]=i-st.top();
            else pref[i]=i+1;
            st.push(i);
        }
        while(!st.empty())st.pop();
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[i]<=arr[st.top()])st.pop();
            if(!st.empty())suff[i]=st.top()-i;
            else suff[i] = n-i;
            st.push(i);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            long long curr = (arr[i]*((pref[i]*suff[i]*1ll)%mod)*1ll)%mod;
            ans = (ans+curr)%mod;
        }
        return ans;
    }
};