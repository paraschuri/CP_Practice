class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        int mod = 1e9 + 7;
        queue<pair<int,int>> q;
        q.push({1,1});
        int d = 2;
        while(d<=n){
            int a = q.size(), x = 0;
            while(a--){
                auto k = q.front();
                q.pop();
                if(k.second+forget>d){
                    q.push(k);
                    if(k.second+delay<=d){
                        x = (x + k.first)%mod;
                    }
                }
            }
            if(x!=0){
                q.push({x,d});
            }
            d++;
        }
        int ans = 0;
        while(!q.empty()){
            auto x = q.front();
            ans = (ans + x.first)%mod;
            q.pop();
        }
        return ans;
    }
};