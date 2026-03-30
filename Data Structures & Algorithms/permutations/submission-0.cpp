class Solution {
public:
    void solvePermute(vector<int>&nums, vector<vector<int>>& sol, int index){
        if(index>=nums.size()){
            sol.push_back(nums);
        }
        // pick elemts and swap
        for(int i = index; i<nums.size(); i++){
            swap(nums[i], nums[index]);
            solvePermute(nums, sol, index+1);
            swap(nums[i], nums[index]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> sol;
        solvePermute(nums, sol, 0);
        return sol;
    }
};
