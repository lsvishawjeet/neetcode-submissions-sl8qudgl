class Solution {
public:
    void dfs(vector<int>& candidates, int target, vector<vector<int>>& sol, vector<int>& curr, int index){
        if(target == 0){
            sol.push_back(curr);
            return;
        }
        if(target < 0 || index >= candidates.size()){
            return;
        }

        curr.push_back(candidates[index]);
        dfs(candidates, target - candidates[index], sol, curr, index+1);
        curr.pop_back();
        // to avoid duplicates pop till index
        while(index+1 < candidates.size() && candidates[index] == candidates[index+1]){
            index++;
        }
        dfs(candidates, target, sol, curr, index+1);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> curr;
        vector<vector<int>> sol;
        sort(candidates.begin(), candidates.end());
        dfs(candidates, target, sol, curr, 0);
        return sol;
    }
};
