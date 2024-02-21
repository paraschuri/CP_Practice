class Solution {
public:
    int trap(vector<int>& arr) {
        int n = arr.size(), ans = 0;
        vector<int> pref(n),suff(n);
        int mx=0;
        for(int i=0;i<n;i++){
            pref[i]=mx;
            mx = max(arr[i],mx);
        }
        mx=0;
        for(int i = n-1;i>=0;i--){
            suff[i]=mx;
            mx = max(arr[i],mx);
        }
        for(int i = 0;i<n;i++){
            ans+=max(0,min(suff[i],pref[i])-arr[i]);
        }
        return ans;
    }
};