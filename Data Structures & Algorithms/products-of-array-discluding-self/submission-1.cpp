class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        /*
            [1,2,4,6]
            [1, 1, 2, 8]
            [48 ,24 , 6 , 1]
        */
        vector<int> prefix(nums.size(), 1);
        vector<int> suffix(nums.size(), 1);
        suffix[nums.size()-1] = suffix[nums.size()-1];
        for(int i=1; i<nums.size(); i++){
            prefix[i] = prefix[i-1]*nums[i-1];
            suffix[nums.size()-i-1] = suffix[nums.size()-i]*nums[nums.size()-i];
        }
        vector<int> output;
        for(int i = 0; i < nums.size(); i++){
            output.push_back(prefix[i]*suffix[i]);
        }
        return output;
    }
};
