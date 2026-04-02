class Solution {
public:
    int dfs(int i, vector<int>& nums, int target, int curr, vector<vector<int>> &dp){
        if(target == curr && i > nums.size()-1){
            return 1;
        }
        if(i >= nums.size()){
            return 0;
        }
        if(dp[i][curr+1000] != -1) return dp[i][curr+1000];
        // take this element as positive and take this element as negative
        return dp[i][curr+1000] = dfs(i+1, nums, target, curr - nums[i], dp) + dfs(i+1, nums, target, curr + nums[i], dp);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        // so its kind of play with negatives and positives
        vector<vector<int>> dp(nums.size(), vector<int>(2002, -1));
        return dfs(0, nums, target, 0, dp);
    }
};
