class Solution{
  public:
    int longestKSubstr(string s, int k) {
    // your code here
        int i=0,j=0,ans=-1;
        map<char,int> mp;
        while(j<s.size()){
            mp[s[j]]++;
            while(mp.size()>k){
                mp[s[i]]--;
                if(!mp[s[i]])mp.erase(s[i]);
                i++;
            }
            if(mp.size()==k){
                ans=max(ans,j-i+1);
            }
            j++;
        }
        return ans;
    }
};