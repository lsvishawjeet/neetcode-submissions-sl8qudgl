class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> el;
        for(int i =0; i<nums.size(); i++){
            int req = target - nums[i];
            if(el.find(req) != el.end()){
                return {el[req], i};
            }
            el[nums[i]] = i;
        }
        return vector<int>{};
    }
};
