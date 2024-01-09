class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size(),m=nums2.size();
        if(n>m){
            return findMedianSortedArrays(nums2,nums1);
        }
        int x=(m+n+1)/2;
        int low=0,high=n;
        while(low<=high){
            int mid=low+(high-low)/2;
            int l1=INT_MIN,l2=INT_MIN,r1=INT_MAX,r2=INT_MAX;
            if(mid<n){
                r1=nums1[mid];
            }
            if(x-mid<m){
                r2=nums2[x-mid];
            }
            if(mid-1>=0){
                l1=nums1[mid-1];
            }
            if(x-mid-1>=0){
                l2=nums2[x-mid-1];
            }
            if(l1<=r2 && l2<=r1){
                if((n+m)&1){
                    return max(l1,l2);
                }
                else{
                    return ((double)(max(l1,l2)+min(r1,r2)))/2.0;
                }
            }
            else if(l1>r2){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return 0;
    }
};