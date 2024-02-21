class Solution {
public:
    float timeRequired(int x, int y, float s){
        return (y-x)/s;
    }
    // 0 1 2
    // 2 3 2
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = speed.size();
        vector<pair<int,int>> arr(n);
        for(int i = 0;i < n;i++){
            arr[i] = {position[i],speed[i]};
        }
        sort(arr.begin(),arr.end());
        stack<pair<int,int>> st;
        st.push(arr[0]);
        for(int i = 1; i<n;i++){
            float currTime = timeRequired(arr[i].first,target,arr[i].second);
            while(!st.empty() && currTime>=timeRequired(st.top().first,target,st.top().second)){
                st.pop();
            }
            st.push(arr[i]);
        }
        return st.size();
    }
};