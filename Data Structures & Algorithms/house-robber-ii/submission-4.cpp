class Solution {
public:
    int robHouse(vector<int>& nums, int houseNo, bool flag, vector<int>& dp){
        if(houseNo >= nums.size()) return 0;
        if(houseNo == nums.size()-1 && flag == true) return 0;
        if(dp[houseNo] != -1) return dp[houseNo];
        return dp[houseNo] = max(robHouse(nums, houseNo+1, flag, dp), nums[houseNo] + robHouse(nums, houseNo+2, flag, dp));
    }
    int rob(vector<int>& nums) {
        // if start node considered then donot consider last node
        // if start node not considred then consider last node
        if(nums.size()==1) return nums[0];
        vector<int>dp(nums.size()+1, -1);
        vector<int>dp2(nums.size()+1, -1);
        return max(robHouse(nums, 0, true, dp), robHouse(nums, 1, false, dp2));
    }
};
