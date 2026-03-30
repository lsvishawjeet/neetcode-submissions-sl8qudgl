class Solution {
public:
    int binarySearch(vector<int>& nums, int target, int l, int r){
        while(l<=r){
            int mid = (l+r)/2;
            if(nums[mid]==target){
                return mid;
            }
            if(target > nums[mid]){
                l = mid+1;
            } else{
                r = mid-1;
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size()-1;
        
        // find the pivot (smallest element)
        while(l<r){
            int mid = (l+r)/2;
            if( nums[r] < nums[mid] ){
                l = mid+1;
            } else{
                r = mid;
            }
        }

        int firstHalf = binarySearch(nums, target, 0, l);
        if(firstHalf!=-1) return firstHalf;

        return binarySearch(nums, target, l, nums.size()-1);
    }
};

