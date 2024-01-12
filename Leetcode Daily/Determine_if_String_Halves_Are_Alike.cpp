class Solution {
public:
    bool isVowel(char c){
        return c=='a' || c=='e' || c=='i' || c=='o' || c=='u' || c=='A' || c=='E' || c=='I' || c=='O' || c=='U';
    }
    bool halvesAreAlike(string s) {
        int cnt=0,n=s.size();
        for(int i=0;i<n;i++){
            if(i<n/2){
                cnt+=(isVowel(s[i]));
            }
            else{
                cnt-=(isVowel(s[i]));
            }
        }
        return cnt==0;
    }
};