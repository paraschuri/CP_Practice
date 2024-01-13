class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> freq1(26,0),freq2(26,0);
        for(auto i: s)freq1[i-'a']++;
        for(auto i: t)freq2[i-'a']++;
        int ans=0;
        for(int i=0;i<26;i++){
            ans+=abs(freq1[i]-freq2[i]);
        }
        return ans/2;
    }
};