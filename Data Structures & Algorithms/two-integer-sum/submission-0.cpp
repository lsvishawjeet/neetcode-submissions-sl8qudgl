class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> mp;

        for(int i=0; i<nums.size(); i++){
            int needNum = target - nums[i];
            if(mp.find(needNum) != mp.end()){
                return {mp[needNum], i};
            }
            mp[nums[i]] = i;
        }
        return {-1,-1};
    }
};
