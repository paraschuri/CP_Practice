class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n=bank.size(),m=bank[0].size();
        vector<int> ones(n,0);
        for(int i=n-1;i>=0;i--){
            int cnt=0;
            for(auto j: bank[i]){
                cnt+=(j=='1');
            }
            if(cnt==0 && i<n-1)ones[i]=ones[i+1];
            else ones[i]=cnt;
        }
        int ans=0;
        for(int i=0;i<n-1;i++){
            int cnt=0;
            for(auto j: bank[i]){
                cnt+=(j=='1');
            }
            ans+=cnt*ones[i+1];
        }
        return ans;
    }
};