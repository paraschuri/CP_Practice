class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n=words.size();
        vector<vector<int>> present(n,vector<int>(26,0));
        for(char c='a';c<='z';c++){
            for(int i=0;i<n;i++){
                if(words[i].find(c)!=string::npos){
                    present[i][c-'a']=1;
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                bool ok=1;
                for(int k=0;k<26;k++){
                    if(present[i][k] && present[j][k]){
                        ok=0;
                        break;
                    }
                }
                if(ok)ans=max(ans,(int)(words[i].size()*words[j].size()));
            }
        }
        return ans;
    }
};