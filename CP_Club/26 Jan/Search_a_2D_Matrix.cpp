class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        int low = 0 , high = n-1, row=-1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(matrix[mid].back()>=target){
                row = mid;
                high=mid-1;
            }
            else{
                low = mid+1;
            }
        }
        if(row==-1)return false;
        low = 0, high = m-1;
        while(low<=high){
            int mid = low + (high - low)/2;
            if(matrix[row][mid]>=target){
                high = mid -1;
            }
            else{
                low = mid + 1;
            }
        }
        return matrix[row][low]==target;
    }
};