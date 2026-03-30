class Solution {
public:
    void dfs(vector<int>&nums, vector<int>& curr, vector<vector<int>> &sol, int i){
        if(i >= nums.size()){
            sol.push_back(curr);
            return;
        }
        // take element
        curr.push_back(nums[i]);
        dfs(nums, curr, sol, i+1);
        //not take
        curr.pop_back();
        while(i+1 < nums.size() && nums[i] == nums[i+1]){
            i++;
        }
        dfs(nums, curr, sol, i+1);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> curr;
        vector<vector<int>> sol;
        dfs(nums, curr, sol, 0);
        return sol;
    }  
};
