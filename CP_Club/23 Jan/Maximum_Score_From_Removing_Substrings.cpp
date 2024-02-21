class Solution {
public:
    int getScore(string& s, char a,char b, int val){
        stack<char> st;
        int n = s.size(), ans = 0;
        for(int i=0;i<n;i++){
            if(!st.empty() && st.top()==a && s[i]==b){
                ans += val;
                st.pop();
            }
            else{
                st.push(s[i]);
            }
        }
        s = "";
        while(!st.empty()){
            s+=st.top();
            st.pop();
        }
        reverse(s.begin(),s.end());
        return ans;
    }
    int maximumGain(string s, int x, int y) {
        if(x>y){
            return getScore(s,'a','b',x) + getScore(s,'b','a',y);
        }
        return getScore(s,'b','a',y)+getScore(s,'a','b',x);
    }
};