class Solution {
public:
    int findMin(vector<int> &nums) {
        // conditions to check:
        // 1. check l and r : if l > r then rotated
        //                       mid > r : l = mid+1
        //                       mid < r : r = mid-1
        //                          
        //      
        int l = 0;
        int r = nums.size()-1;
        int minNum = INT_MAX;

        if(nums[l] < nums[r]) return nums[l];

        while(l<=r){
            int mid = (r+l)/2;
            if(nums[mid] > nums[r]){
                l = mid+1;
            } else {
                minNum = min(minNum, nums[mid]);
                r = mid-1;
            }
        }        
        return minNum;       
    }
};
