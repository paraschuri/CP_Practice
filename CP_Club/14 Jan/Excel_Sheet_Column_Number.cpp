class Solution {
public:
    int titleToNumber(string s) {
        int ans=0,n=s.size();
        for(int i=0;i<n;i++){
            ans+=(s[i]-'A'+1)*pow(26,(n-i-1));
        }
        return ans;
    }
};