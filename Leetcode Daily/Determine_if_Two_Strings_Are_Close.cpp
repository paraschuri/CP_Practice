    class Solution {
public:
    bool closeStrings(string word1, string word2) {
        vector<int> freq1(26,0),freq2(26,0);
        for(auto i: word1)freq1[i-'a']++;
        for(auto i: word2)freq2[i-'a']++;
        sort(freq1.begin(),freq1.end());
        sort(freq2.begin(),freq2.end());
        for(int i=0;i<26;i++){
            if(freq1[i]!=freq2[i])return false;
        }
        return true;
    }
};