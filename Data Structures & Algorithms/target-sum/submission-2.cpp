class Solution {
public:
    int dfs(int i, vector<int>& nums, int target, int curr){
        if(target == curr && i > nums.size()-1){
            return 1;
        }
        if(i >= nums.size()){
            return 0;
        }
        // take this element as positive and take this element as negative
        return dfs(i+1, nums, target, curr - nums[i]) + dfs(i+1, nums, target, curr + nums[i]);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        // so its kind of play with negatives and positives
        return dfs(0, nums, target, 0);
    }
};
