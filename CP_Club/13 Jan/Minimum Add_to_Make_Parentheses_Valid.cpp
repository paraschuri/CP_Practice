class Solution {
public:
    int minAddToMakeValid(string s) {
        int cnt=0,ans=0;
        for(auto i: s){
            if(i=='('){
                cnt++;
            }
            else{
                if(cnt)cnt--;
                else ans++;
            }
        }
        return ans+cnt;
    }
};