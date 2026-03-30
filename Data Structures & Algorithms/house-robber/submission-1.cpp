class Solution {
public:
    int robHouse(vector<int>& nums, int i, vector<int>& dp){
        if(nums.size() <= i){
            return 0;
        }
        if(dp[i] != -1) return dp[i];
        // can skip the house 
        // can rob the house
        return dp[i] = max(robHouse(nums, i+1, dp), nums[i] + robHouse(nums, i+2, dp));
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size()+1, -1);
        return robHouse(nums, 0, dp);
    }
};
