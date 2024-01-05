class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int ans=1,n=points.size();
        for(int i=0;i<n;i++){
            unordered_map<float,int> mp;
            int cnt=1;
            for(int j=0;j<n;j++){
                if(i==j)continue;
                float slope;
                if(points[i][0]==points[j][0]){
                    cnt++;
                    ans=max(ans,cnt); 
                }
                else{
                    slope = (points[i][1]-points[j][1])*1.0/(points[i][0]-points[j][0]);
                    mp[slope]++;
                    ans=max(ans,mp[slope]+1);
                }
            }
        }
        return ans;
    }
};