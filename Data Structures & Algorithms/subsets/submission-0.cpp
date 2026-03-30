class Solution {
public:
    void addSubSets(vector<vector<int>>& subSets, vector<int>& subSet, vector<int>& nums, int index){
        if(index >= nums.size()){
            subSets.push_back(subSet);
            return;
        }
        //take
        subSet.push_back(nums[index]);
        addSubSets(subSets, subSet, nums, index+1);
        //notTake
        subSet.pop_back();
        addSubSets(subSets, subSet, nums, index+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> subSets;
        vector<int> subSet;
        addSubSets(subSets, subSet, nums, 0);
        return subSets;
    }
};
