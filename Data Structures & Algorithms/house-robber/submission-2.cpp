class Solution {
public:
    // int robHouse(vector<int>& nums, int i, vector<int>& dp){
    //     if(nums.size() <= i){
    //         return 0;
    //     }
    //     if(dp[i] != -1) return dp[i];
    //     // can skip the house 
    //     // can rob the house
    //     return dp[i] = max(robHouse(nums, i+1, dp), nums[i] + robHouse(nums, i+2, dp));
    // }
    int rob(vector<int>& nums) {
        // vector<int> dp(nums.size()+1);
        /*
            I can either rob first house or skip first house
            Rob, skip, rob
            skip, rob, skip
            rob, skip, skip, rob
            In dp array, at ith index store the max amount he can rob
            in example 6,1,1,8,3
            // at each step to skip dp[i] = dp[i-1] and to take dp[i] = i + dp[i-2]
            // at 0 -> 6
            // at 1 -> max(6,6) = 6
            // at 2 -> max(6, 1+6) = 7
            // at 3 -> max(7, 8+6) = 14
            // at 4 -> max(14, 3+7) = 14

        */
        if(nums.size()==0) return 0;
        if(nums.size()==1) return nums[0];
        vector<int> dp(nums.size());
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for(int i=2; i<nums.size(); i++){
            dp[i] = max(dp[i-1], nums[i] + dp[i-2]);
        }
        return dp[nums.size()-1];
    }
};
