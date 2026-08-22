class Solution {
public:
    void dfs(vector<int>& nums, int target, vector<vector<int>>& sol, vector<int> &curr, int i){
        if(i > nums.size()-1 || target<0){
            return;
        }
        if(target == 0){
            sol.push_back(curr);
            return;
        }
        curr.push_back(nums[i]);
        dfs(nums, target-nums[i], sol, curr, i);
        curr.pop_back();
        dfs(nums, target, sol, curr, i+1);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> sol;
        vector<int> curr;
        dfs(nums, target, sol, curr, 0);
        return sol;
    }
};
