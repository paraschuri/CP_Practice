class Solution {
public:
    string removeKdigits(string s, int k) {
        stack<char> st;
        int n=s.size();
        // if(k==n)return "0";
        k=n-k;
        for(int i=0;i<n;i++){
            while(!st.empty() && s[i]<st.top() && n-i-1+st.size()>=k){
                st.pop();
            }
            st.push(s[i]);
        }
        while(st.size()>k)st.pop();
        string ans="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        while(ans.size() && ans[0]=='0')ans.erase(ans.begin());
        if(ans.empty())return "0";
        return ans;
    }
};