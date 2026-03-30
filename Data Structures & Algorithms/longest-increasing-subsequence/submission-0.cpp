class Solution {
public:
    int dfs(vector<int>& nums, int i, int el){
        if(i>=nums.size()) return 0;
        int take = INT_MIN;
        if(nums[i] > el){
            cout<<nums[i]<<endl;
            take = 1 + dfs(nums, i+1, nums[i]);
        }
        int skip = dfs(nums, i+1, el);
        cout<<endl;
        return max(take, skip);
    }
    int lengthOfLIS(vector<int>& nums) {
        int count = 0;
        // for(int i=0; i<nums.size(); i++){
            count = max(count, dfs(nums, 0, INT_MIN));
        
        return count;
    }
};
