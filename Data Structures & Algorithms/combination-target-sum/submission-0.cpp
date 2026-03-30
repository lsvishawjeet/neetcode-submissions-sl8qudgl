class Solution {
public:
    void addCombinationToSol(vector<int>& nums, int target, vector<vector<int>>& sol, vector<int>& combination, int index){
        if(target == 0){
            sol.push_back(combination);
            return;
        }
        if(target < 0 || index >= nums.size()){
            return;
        }
        combination.push_back(nums[index]);
        addCombinationToSol(nums, target-nums[index], sol, combination, index);
        combination.pop_back();
        addCombinationToSol(nums, target, sol, combination, index+1);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> sol;
        vector<int> combination;
        addCombinationToSol(nums, target, sol, combination, 0);
        return sol;
    }
};
