class Solution {
public:
    string getHint(string secret, string guess) {
        int cnt1=0,cnt2=0,n=guess.size();
        vector<int> freq(10,0);
        for(int i=0;i<n;i++){
            cnt1+=(secret[i]==guess[i]);
            if(secret[i]!=guess[i])freq[secret[i]-'0']++;
        }
        for(int i=0;i<n;i++){
            if(freq[guess[i]-'0'] && secret[i]!=guess[i]){
                cnt2++;
                freq[guess[i]-'0']--;
            }
        }
        string a=to_string(cnt1),b=to_string(cnt2);
        return a+"A"+b+"B";
    }
};