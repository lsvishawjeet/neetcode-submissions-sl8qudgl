class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // create all subarrays and calculate the sum
        int sum = nums[0];
        for(int i = 0; i<nums.size(); i++){
            int temp = 0;
            for(int j=i; j<nums.size(); j++){
                temp += nums[j];
                sum = max(sum, temp);
            }
        }
        return sum;
    }
};
