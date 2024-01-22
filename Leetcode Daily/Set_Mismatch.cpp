#define ll long long
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        ll n = nums.size();
        ll sum = n*(n+1)/2,sumSquares = n*(n+1)*(2*n+1)/6;
        ll arrSum = 0, arrSumSquares = 0;
        for(ll i: nums){
            arrSum += i;
            arrSumSquares += i*i;
        }
        ll diff = sum - arrSum;
        ll squareDiff = sumSquares - arrSumSquares;
        ll temp = squareDiff/diff;
        int missing = (diff+temp)/2;
        int repeating = missing - diff;
        return {repeating,missing};
    }
};