class Solution {
public:
    bool isPalindrome(int i,int j,string& s){
        while(i<j){
            if(s[i++]!=s[j--])return false;
        }
        return true;
    }
    vector<vector<string>> ans;
    void solve(int i,int j,vector<string> &temp,string& s){
        if(j==s.size()){
            if(i==j){
                ans.push_back(temp);
            }
            return;
        }
        if(isPalindrome(i,j,s)){
            temp.push_back(s.substr(i,j-i+1));
            solve(j+1,j+1,temp,s);
            temp.pop_back();
        }
        solve(i,j+1,temp,s);
    }
    vector<vector<string>> partition(string s) {
        vector<string> temp;
        solve(0,0,temp,s);
        return ans;
    }
};